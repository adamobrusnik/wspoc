#include "soappocService.h"
#include "poc.nsmap"

int main() {
	pocService server;
	server.serve();
	server.destroy();
} // end main

int pocService::getS(
    std::string                         species1,
    std::string                         species2,
    unsigned int                        s,	
    double                              x0,
    double                              Tmin,
    double                              Tmax,
    double                              Npoints,
    bool                                logaritmic,
    double                             &dat	
) {

dat = 42;
return SOAP_OK;

}
