/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0310"
 * 	found in "../tap3.asn1"
 * 	`asn1c -S ../../skeletons`
 */

#ifndef	_Description_H_
#define	_Description_H_


#include <asn_application.h>

/* Including external dependencies */
#include "AsciiString.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Description */
typedef AsciiString_t	 Description_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_Description;
asn_struct_free_f Description_free;
asn_struct_print_f Description_print;
asn_constr_check_f Description_constraint;
ber_type_decoder_f Description_decode_ber;
der_type_encoder_f Description_encode_der;
xer_type_decoder_f Description_decode_xer;
xer_type_encoder_f Description_encode_xer;

#ifdef __cplusplus
}
#endif

#endif	/* _Description_H_ */
#include <asn_internal.h>
