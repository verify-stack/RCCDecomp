// this is gonna be something else until we can find the decompile source
// from the 2016 source code leak

#include "stdafx.h"
#include "gSOAP/generated/soapRCCServiceSoapService.h"

int RCCServiceSoapService::HelloWorld(_ns1__HelloWorld *ns1__HelloWorld, _ns1__HelloWorldResponse *ns1__HelloWorldResponse)
{
	puts("HelloWorld");
	ns1__HelloWorldResponse->HelloWorldResult = soap_new_std__string(this, -1);
	*ns1__HelloWorldResponse->HelloWorldResult = "Hello World";

	return 0;
}

int RCCServiceSoapService::Diag(_ns1__Diag *ns1__Diag, _ns1__DiagResponse *ns1__DiagResponse)
{
	puts("Diag");
	puts("Diag is not a supported type");

	return 0;
}
int RCCServiceSoapService::DiagEx(_ns1__DiagEx *ns1__DiagEx, _ns1__DiagExResponse *ns1__DiagExResponse)
{
	puts("DiagEx");
	puts("DiagEx is not a supported type");

	return 0;
}

int RCCServiceSoapService::GetVersion(_ns1__GetVersion *ns1__GetVersion, _ns1__GetVersionResponse *ns1__GetVersionResponse)
{
	ns1__GetVersionResponse->GetVersionResult = "123"; // until we have a proper var for this, keep it like this

	return 0;
}

int RCCServiceSoapService::GetStatus(_ns1__GetStatus *ns1__GetStatus, _ns1__GetStatusResponse *ns1__GetStatusResponse)
{
	puts("GetStatus");
	puts("GetStatus is not a supported type yet");

	return 0;
}

int RCCServiceSoapService::OpenJob(_ns1__OpenJob *ns1__OpenJob, _ns1__OpenJobResponse *ns1__OpenJobResponse)
{
	puts("OpenJob");
	puts("OpenJob is not a supported type yet");

	return 0;
}

int RCCServiceSoapService::OpenJobEx(_ns1__OpenJobEx *ns1__OpenJobEx, _ns1__OpenJobExResponse *ns1__OpenJobExResponse)
{
	puts("OpenJobEx");
	puts("OpenJobEx is not a supported type yet");

	return 0;
}

int RCCServiceSoapService::Execute(_ns1__Execute *ns1__Execute, _ns1__ExecuteResponse *ns1__ExecuteResponse)
{
	puts("Execute");
	puts("Execute is not a supported type yet");

	return 0;
}

int RCCServiceSoapService::ExecuteEx(_ns1__ExecuteEx *ns1__ExecuteEx, _ns1__ExecuteExResponse *ns1__ExecuteExResponse)
{
	puts("ExecuteEx");
	puts("ExecuteEx is not a supported type");

	return 0;
}


int RCCServiceSoapService::CloseJob(_ns1__CloseJob *ns1__CloseJob, _ns1__CloseJobResponse *ns1__CloseJobResponse)
{
	puts("CloseJob");
	puts("CloseJob is not a supported type yet");

	return 0;
}

int RCCServiceSoapService::RenewLease(_ns1__RenewLease *ns1__RenewLease, _ns1__RenewLeaseResponse *ns1__RenewLeaseResponse)
{
	puts("RenewLease");
	puts("RenewLease is not a supported type");

	return 0;
}

int RCCServiceSoapService::BatchJob(_ns1__BatchJob *ns1__BatchJob, _ns1__BatchJobResponse *ns1__BatchJobResponse)
{
	puts("BatchJob");
	puts("BatchJob is not a supported type yet");

	return 0;
}


int RCCServiceSoapService::BatchJobEx(_ns1__BatchJobEx *ns1__BatchJobEx, _ns1__BatchJobExResponse *ns1__BatchJobExResponse)
{
	puts("BatchJobEx");
	puts("BatchJobEx is not a supported type");

	return 0;
}

int RCCServiceSoapService::GetExpiration(_ns1__GetExpiration *ns1__GetExpiration, _ns1__GetExpirationResponse *ns1__GetExpirationResponse)
{
	puts("GetExpiration");
	puts("GetExpiration is not a supported type yet");

	return 0;
}

int RCCServiceSoapService::GetAllJobs(_ns1__GetAllJobs *ns1__GetAllJobs, _ns1__GetAllJobsResponse *ns1__GetAllJobsResponse)
{
	puts("GetAllJobs");
	puts("GetAllJobs is not a supported type yet");

	return 0;
}

int RCCServiceSoapService::GetAllJobsEx(_ns1__GetAllJobsEx *ns1__GetAllJobsEx, _ns1__GetAllJobsExResponse *ns1__GetAllJobsExResponse)
{
	puts("GetAllJobsEx");
	puts("GetAllJobsEx is not a supported type");

	return 0;
}

int RCCServiceSoapService::CloseExpiredJobs(_ns1__CloseExpiredJobs *ns1__CloseExpiredJobs, _ns1__CloseExpiredJobsResponse *ns1__CloseExpiredJobsResponse)
{
	puts("CloseExpiredJobs");
	puts("CloseExpiredJobs is not a supported type yet");

	return 0;
}

int RCCServiceSoapService::CloseAllJobs(_ns1__CloseAllJobs *ns1__CloseAllJobs, _ns1__CloseAllJobsResponse *ns1__CloseAllJobsResponse)
{
	puts("CloseAllJobs");
	puts("CloseAllJobs is not a supported type yet");

	return 0;
}