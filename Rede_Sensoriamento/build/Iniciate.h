/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "Ativo"
 * 	found in "../Ativo.asn1"
 */

#ifndef	_Iniciate_H_
#define	_Iniciate_H_


#include <asn_application.h>

/* Including external dependencies */
#include <PrintableString.h>
#include <NativeInteger.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Iniciate */
typedef struct Iniciate {
	PrintableString_t	 name;
	PrintableString_t	 atop;
	long	 type;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} Iniciate_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_Iniciate;

#ifdef __cplusplus
}
#endif

#endif	/* _Iniciate_H_ */
#include <asn_internal.h>