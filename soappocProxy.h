/* soappocProxy.h
   Generated by gSOAP 2.8.7 from test.h

Copyright(C) 2000-2011, Robert van Engelen, Genivia Inc. All Rights Reserved.
The generated code is released under one of the following licenses:
1) GPL or 2) Genivia's license for commercial use.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
*/

#ifndef soappocProxy_H
#define soappocProxy_H
#include "soapH.h"

class SOAP_CMAC pocProxy : public soap
{ public:
	/// Endpoint URL of service 'pocProxy' (change as needed)
	const char *soap_endpoint;
	/// Constructor
	pocProxy();
	/// Constructor with copy of another engine state
	pocProxy(const struct soap&);
	/// Constructor with endpoint URL
	pocProxy(const char *url);
	/// Constructor with engine input+output mode control
	pocProxy(soap_mode iomode);
	/// Constructor with URL and input+output mode control
	pocProxy(const char *url, soap_mode iomode);
	/// Constructor with engine input and output mode control
	pocProxy(soap_mode imode, soap_mode omode);
	/// Destructor frees deserialized data
	virtual	~pocProxy();
	/// Initializer used by constructors
	virtual	void pocProxy_init(soap_mode imode, soap_mode omode);
	/// Delete all deserialized data (uses soap_destroy and soap_end)
	virtual	void destroy();
	/// Disables and removes SOAP Header from message
	virtual	void soap_noheader();
	/// Get SOAP Header structure (NULL when absent)
	virtual	const SOAP_ENV__Header *soap_header();
	/// Get SOAP Fault structure (NULL when absent)
	virtual	const SOAP_ENV__Fault *soap_fault();
	/// Get SOAP Fault string (NULL when absent)
	virtual	const char *soap_fault_string();
	/// Get SOAP Fault detail as string (NULL when absent)
	virtual	const char *soap_fault_detail();
	/// Close connection (normally automatic, except for send_X ops)
	virtual	int soap_close_socket();
	/// Force close connection (can kill a thread blocked on IO)
	virtual	int soap_force_close_socket();
	/// Print fault
	virtual	void soap_print_fault(FILE*);
#ifndef WITH_LEAN
	/// Print fault to stream
#ifndef WITH_COMPAT
	virtual	void soap_stream_fault(std::ostream&);
#endif

	/// Put fault into buffer
	virtual	char *soap_sprint_fault(char *buf, size_t len);
#endif

	/// Web service operation 'getS' (returns error code or SOAP_OK)
	virtual	int getS(std::string species1, std::string species2, unsigned int s, double x0, double Tmin, double Tmax, double Npoints, bool logaritmic, double &dat) { return getS(NULL, NULL, species1, species2, s, x0, Tmin, Tmax, Npoints, logaritmic, dat); }
	virtual	int getS(const char *endpoint, const char *soap_action, std::string species1, std::string species2, unsigned int s, double x0, double Tmin, double Tmax, double Npoints, bool logaritmic, double &dat);
};
#endif
