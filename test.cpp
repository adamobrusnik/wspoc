#include "soapH.h"
#include "poc.nsmap"
#include "soapStub.h"
int main() {
	// this creates a SOAP context and serves a singe CGI-based request
	// this will probably need to be done differently in future as this is quite a slow way of dealin user requests
	// spawns a separate process for each request
	return soap_serve(soap_new());
} // end main

int ns2__getS(
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
