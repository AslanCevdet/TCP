#include <FreeRTOS.h>
#include "FreeRTOS_IP.h"
#include "FreeRTOS_Sockets.h"
#include "FreeRTOS_DHCP.h"




BaseType_t xNetworkInterfaceOutput( NetworkBufferDescriptor_t * const pxNetworkBuffer,
                                    BaseType_t bReleaseAfterSend )
{
    /* Provide a stub for this function. */
    return pdTRUE;
}

BaseType_t xNetworkInterfaceInitialise( void )
{
    /* Provide a stub for this function. */
    return pdTRUE;
}

#if ( ( ipconfigUSE_TCP == 1 ) && ( ipconfigUSE_DHCP_HOOK != 0 ) )
    eDHCPCallbackAnswer_t xApplicationDHCPHook( eDHCPCallbackPhase_t eDHCPPhase,
                                                uint32_t ulIPAddress )
    {
        /* Provide a stub for this function. */
        return eDHCPContinue;
    }
#endif

void vApplicationPingReplyHook( ePingReplyStatus_t eStatus,
                                uint16_t usIdentifier )
{
    /* Provide a stub for this function. */
}

void vApplicationIPNetworkEventHook( eIPCallbackEvent_t eNetworkEvent )
{
    static BaseType_t xTasksAlreadyCreated = pdFALSE;

    /* If the network has just come up...*/
    if( ( eNetworkEvent == eNetworkUp ) && ( xTasksAlreadyCreated == pdFALSE ) )
    {
        /* Do nothing. Just a stub. */

        xTasksAlreadyCreated = pdTRUE;
    }
}

#if ( ( ipconfigUSE_LLMNR != 0 ) || \
    ( ipconfigUSE_NBNS != 0 ) ||    \
    ( ipconfigDHCP_REGISTER_HOSTNAME == 1 ) )

    const char * pcApplicationHostnameHook( void )
    {
        /* This function will be called during the DHCP: the machine will be registered
         * with an IP address plus this name. */
        return mainHOST_NAME;
    }

#endif /* if ( ( ipconfigUSE_LLMNR != 0 ) || ( ipconfigUSE_NBNS != 0 ) || ( ipconfigDHCP_REGISTER_HOSTNAME == 1 ) ) */

#if ( ipconfigUSE_LLMNR != 0 ) || ( ipconfigUSE_NBNS != 0 )

    BaseType_t xApplicationDNSQueryHook( const char * pcName )
    {
        BaseType_t xReturn;

        /* Determine if a name lookup is for this node.  Two names are given
         * to this node: that returned by pcApplicationHostnameHook() and that set
         * by mainDEVICE_NICK_NAME. */
        if( _stricmp( pcName, pcApplicationHostnameHook() ) == 0 )
        {
            xReturn = pdPASS;
        }
        else if( _stricmp( pcName, mainDEVICE_NICK_NAME ) == 0 )
        {
            xReturn = pdPASS;
        }
        else
        {
            xReturn = pdFAIL;
        }

        return xReturn;
    }

#endif /* if ( ipconfigUSE_LLMNR != 0 ) || ( ipconfigUSE_NBNS != 0 ) */
/*-----------------------------------------------------------*/
