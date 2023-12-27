#include <FreeRTOS_IP.h>
#include <sys/_stdint.h>
#include "portmacro.h"

BaseType_t xNetworkInterfaceOutput( NetworkBufferDescriptor_t * const pxNetworkBuffer,
                                    BaseType_t bReleaseAfterSend );

BaseType_t xNetworkInterfaceInitialise( void );

void vApplicationPingReplyHook( ePingReplyStatus_t eStatus,
                                uint16_t usIdentifier );
void vApplicationIPNetworkEventHook( eIPCallbackEvent_t eNetworkEvent );
