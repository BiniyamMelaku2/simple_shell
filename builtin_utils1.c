#include "shell.h"

/**
 * _setenv - sets environment variable
 * @env: the current environment
 * Return: 0 on success.
 */
int _setenv(char ***env)
{
char *env_var, *env_val;
env_var = strtok(NULL, " \n");
if (env_var == NULL)
{
p_error("missing argument\n");
return (1);
}
env_val = strtok(NULL, " \n");
if (env_val == NULL)
{
p_error("missing value\n");
return (1);
}
return (_setenv_func(env, env_var, env_val));
}
/**
 * _setenv_func - helps _setenv
 * @env: the current environment
 * @env_var: enviroment variable name
 * @env_val: enviroment variable value
 * Return: 0 on success
 */
int _setenv_func(char ***env, char *env_var, char *env_val)
{
char **new_env;
int i;
for (i = 0; (*env)[i] != NULL; i++)
{
if (_cstrcmp((*env)[i], env_var) == 0)
{
free((*env)[i]);
(*env)[i] = new_path_str(env_var, env_val);
return (0);
}
}
new_env = grow_env(*env, i);
if (env == NULL)
{
perror("grow_env");
return (1);
}
free(*env);
*env = new_env;
(*env)[i] = new_path_str(env_var, env_val);
print((*env)[i]);
putch('\n');
(*env)[++i] = NULL;
return (0);
}
/**
 * grow_env - grow env by one, copy all the present key-value pairs
 * @env: the current environment
 * @env_size: the size of the current environment, not including '\0'.
 * Return: the new environment, NULL on memory error.
 */
char **grow_env(char **env, int env_size)
{
int i;
char **new_env;
/* grow environment by one + NULL pointer */
new_env = malloc(sizeof(char **) * (env_size + 2));
if (new_env == NULL)
{
perror("malloc");
return (NULL);
}
/* copy all the pointers to strings to new environment */
for (i = 0; i < env_size; i++)
new_env[i] = env[i];
/* return new environment */
return (new_env);
}
/**
 * new_path_str - new string with format "variable" + '=' + "value"
 * @env_var: environment variable name
 * @env_val: environment variable value
 * Return: the new PATH string.
 */
char *new_path_str(char *env_var, char *env_val)
{
int env_var_len, env_val_len, path_len = 0;
char *path_str;
env_var_len = _strlen(env_var);
env_val_len = _strlen(env_val);
/* '=' + '\0' --> 2 additional chars */
path_len = env_var_len + env_val_len + 2;
path_str = malloc(sizeof(char) * (path_len));
if (path_str == NULL)
{
perror("malloc");
exit(EXIT_FAILURE);
}
_memset(path_str, '\0', path_len);
path_str = _strcat(path_str, env_var);
path_str = _strcat(path_str, "=");
path_str = _strcat(path_str, env_val);
return (path_str);
}
