void imprimirLista(ArrayList* pPedidos);
void imprimirPedido(void* pedido);
void imprimirLocalidad(void* pedido);
void listarLocalidades(ArrayList* pPedidos, ArrayList* pLocalidades);
int buscarLocalidad(ArrayList* pLocalidades,char* locPed);
int buscarLocalidadPedidos(ArrayList* pPedidos,char* auxLocalidad);
void imprimirPedidosPorLoc(ArrayList* pPedidos,char* auxLocalidad);
void guardarPedidos(ArrayList* pPedidos);
