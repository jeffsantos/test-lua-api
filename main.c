#include <stdio.h>
#include <string.h>

#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"


int main(void) {
    char buff[256];
    int error;

    printf("Início\n");
    
    lua_State *L = luaL_newstate(); /* abre lua */
    luaL_openlibs(L); /* abre bibliotecas padrão */

    while (fgets(buff, sizeof(buff), stdin) != NULL) {  /* enquanto consegue passar pro buff algo de stdin */
        error = luaL_loadstring(L, buff) || lua_pcall(L, 0, 0, 0);  /* executa a string no buffer */
        if (error) {
            fprintf(stderr, "%s\n", lua_tostring(L, -1));  /* mostra o resultado da execução */
            lua_pop(L, 1);  /* desempilha mensagens de erro */
        }
    }

    lua_close(L);
    printf("Hello World listagem-25-1\n");
    return 0;
}