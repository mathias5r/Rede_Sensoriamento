/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0310"
 * 	found in "../tap3.asn1"
 * 	`asn1c -S ../../skeletons`
 */

#ifndef	_QoSGuaranteedBitRateUplink_H_
#define	_QoSGuaranteedBitRateUplink_H_


#include <asn_application.h>

/* Including external dependencies */
#include <OCTET_STRING.h>

#ifdef __cplusplus
extern "C" {
#endif

/* QoSGuaranteedBitRateUplink */
typedef OCTET_STRING_t	 QoSGuaranteedBitRateUplink_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_QoSGuaranteedBitRateUplink;
asn_struct_free_f QoSGuaranteedBitRateUplink_free;
asn_struct_print_f QoSGuaranteedBitRateUplink_print;
asn_constr_check_f QoSGuaranteedBitRateUplink_constraint;
ber_type_decoder_f QoSGuaranteedBitRateUplink_decode_ber;
der_type_encoder_f QoSGuaranteedBitRateUplink_encode_der;
xer_type_decoder_f QoSGuaranteedBitRateUplink_decode_xer;
xer_type_encoder_f QoSGuaranteedBitRateUplink_encode_xer;

#ifdef __cplusplus
}
#endif

#endif	/* _QoSGuaranteedBitRateUplink_H_ */
#include <asn_internal.h>
