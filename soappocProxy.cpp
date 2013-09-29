/* soappocProxy.cpp
   Generated by gSOAP 2.8.7 from test.h

Copyright(C) 2000-2011, Robert van Engelen, Genivia Inc. All Rights Reserved.
The generated code is released under one of the following licenses:
1) GPL or 2) Genivia's license for commercial use.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
*/

#include "soappocProxy.h"

pocProxy::pocProxy()
{	pocProxy_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
}

pocProxy::pocProxy(const struct soap &_soap) : soap(_soap)
{ }

pocProxy::pocProxy(const char *url)
{	pocProxy_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
	soap_endpoint = url;
}

pocProxy::pocProxy(soap_mode iomode)
{	pocProxy_init(iomode, iomode);
}

pocProxy::pocProxy(const char *url, soap_mode iomode)
{	pocProxy_init(iomode, iomode);
	soap_endpoint = url;
}

pocProxy::pocProxy(soap_mode imode, soap_mode omode)
{	pocProxy_init(imode, omode);
}

pocProxy::~pocProxy()
{ }

void pocProxy::pocProxy_init(soap_mode imode, soap_mode omode)
{	soap_imode(this, imode);
	soap_omode(this, omode);
	soap_endpoint = NULL;
	static const struct Namespace namespaces[] =
{
	{"SOAP-ENV", "http://schemas.xmlsoap.org/soap/envelope/", "http://www.w3.org/*/soap-envelope", NULL},
	{"SOAP-ENC", "http://schemas.xmlsoap.org/soap/encoding/", "http://www.w3.org/*/soap-encoding", NULL},
	{"xsi", "http://www.w3.org/2001/XMLSchema-instance", "http://www.w3.org/*/XMLSchema-instance", NULL},
	{"xsd", "http://www.w3.org/2001/XMLSchema", "http://www.w3.org/*/XMLSchema", NULL},
	{"ns2", "urn:poc", NULL, NULL},
	{NULL, NULL, NULL, NULL}
};
	soap_set_namespaces(this, namespaces);
}

void pocProxy::destroy()
{	soap_destroy(this);
	soap_end(this);
}

void pocProxy::soap_noheader()
{	this->header = NULL;
}

const SOAP_ENV__Header *pocProxy::soap_header()
{	return this->header;
}

const SOAP_ENV__Fault *pocProxy::soap_fault()
{	return this->fault;
}

const char *pocProxy::soap_fault_string()
{	return *soap_faultstring(this);
}

const char *pocProxy::soap_fault_detail()
{	return *soap_faultdetail(this);
}

int pocProxy::soap_close_socket()
{	return soap_closesock(this);
}

int pocProxy::soap_force_close_socket()
{	return soap_force_closesock(this);
}

void pocProxy::soap_print_fault(FILE *fd)
{	::soap_print_fault(this, fd);
}

#ifndef WITH_LEAN
#ifndef WITH_COMPAT
void pocProxy::soap_stream_fault(std::ostream& os)
{	::soap_stream_fault(this, os);
}
#endif

char *pocProxy::soap_sprint_fault(char *buf, size_t len)
{	return ::soap_sprint_fault(this, buf, len);
}
#endif

int pocProxy::getS(const char *endpoint, const char *soap_action, std::string species1, std::string species2, unsigned int s, double x0, double Tmin, double Tmax, double Npoints, bool logaritmic, double &dat)
{	struct soap *soap = this;
	struct ns2__getS soap_tmp_ns2__getS;
	struct ns2__getSResponse *soap_tmp_ns2__getSResponse;
	if (endpoint)
		soap_endpoint = endpoint;
	if (!soap_endpoint)
		soap_endpoint = "http://95.154.243.111/~ws/pos/testserver.cgi";
	if (!soap_action)
		soap_action = "";
	soap->encodingStyle = "http://schemas.xmlsoap.org/soap/encoding/";
	soap_tmp_ns2__getS.species1 = species1;
	soap_tmp_ns2__getS.species2 = species2;
	soap_tmp_ns2__getS.s = s;
	soap_tmp_ns2__getS.x0 = x0;
	soap_tmp_ns2__getS.Tmin = Tmin;
	soap_tmp_ns2__getS.Tmax = Tmax;
	soap_tmp_ns2__getS.Npoints = Npoints;
	soap_tmp_ns2__getS.logaritmic = logaritmic;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ns2__getS(soap, &soap_tmp_ns2__getS);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns2__getS(soap, &soap_tmp_ns2__getS, "ns2:getS", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns2__getS(soap, &soap_tmp_ns2__getS, "ns2:getS", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!&dat)
		return soap_closesock(soap);
	soap_default_double(soap, &dat);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	if (soap_recv_fault(soap, 1))
		return soap->error;
	soap_tmp_ns2__getSResponse = soap_get_ns2__getSResponse(soap, NULL, "", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	dat = soap_tmp_ns2__getSResponse->dat;
	return soap_closesock(soap);
}
/* End of client proxy code */
