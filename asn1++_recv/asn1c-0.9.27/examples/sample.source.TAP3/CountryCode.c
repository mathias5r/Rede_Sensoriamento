/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0310"
 * 	found in "../tap3.asn1"
 * 	`asn1c -S ../../skeletons`
 */

#include "CountryCode.h"

int
CountryCode_constraint(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	/* Replace with underlying type checker */
	td->check_constraints = asn_DEF_NumberString.check_constraints;
	return td->check_constraints(td, sptr, ctfailcb, app_key);
}

/*
 * This type is implemented using NumberString,
 * so here we adjust the DEF accordingly.
 */
static void
CountryCode_1_inherit_TYPE_descriptor(asn_TYPE_descriptor_t *td) {
	td->free_struct    = asn_DEF_NumberString.free_struct;
	td->print_struct   = asn_DEF_NumberString.print_struct;
	td->check_constraints = asn_DEF_NumberString.check_constraints;
	td->ber_decoder    = asn_DEF_NumberString.ber_decoder;
	td->der_encoder    = asn_DEF_NumberString.der_encoder;
	td->xer_decoder    = asn_DEF_NumberString.xer_decoder;
	td->xer_encoder    = asn_DEF_NumberString.xer_encoder;
	td->uper_decoder   = asn_DEF_NumberString.uper_decoder;
	td->uper_encoder   = asn_DEF_NumberString.uper_encoder;
	if(!td->per_constraints)
		td->per_constraints = asn_DEF_NumberString.per_constraints;
	td->elements       = asn_DEF_NumberString.elements;
	td->elements_count = asn_DEF_NumberString.elements_count;
	td->specifics      = asn_DEF_NumberString.specifics;
}

void
CountryCode_free(asn_TYPE_descriptor_t *td,
		void *struct_ptr, int contents_only) {
	CountryCode_1_inherit_TYPE_descriptor(td);
	td->free_struct(td, struct_ptr, contents_only);
}

int
CountryCode_print(asn_TYPE_descriptor_t *td, const void *struct_ptr,
		int ilevel, asn_app_consume_bytes_f *cb, void *app_key) {
	CountryCode_1_inherit_TYPE_descriptor(td);
	return td->print_struct(td, struct_ptr, ilevel, cb, app_key);
}

asn_dec_rval_t
CountryCode_decode_ber(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const void *bufptr, size_t size, int tag_mode) {
	CountryCode_1_inherit_TYPE_descriptor(td);
	return td->ber_decoder(opt_codec_ctx, td, structure, bufptr, size, tag_mode);
}

asn_enc_rval_t
CountryCode_encode_der(asn_TYPE_descriptor_t *td,
		void *structure, int tag_mode, ber_tlv_tag_t tag,
		asn_app_consume_bytes_f *cb, void *app_key) {
	CountryCode_1_inherit_TYPE_descriptor(td);
	return td->der_encoder(td, structure, tag_mode, tag, cb, app_key);
}

asn_dec_rval_t
CountryCode_decode_xer(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const char *opt_mname, const void *bufptr, size_t size) {
	CountryCode_1_inherit_TYPE_descriptor(td);
	return td->xer_decoder(opt_codec_ctx, td, structure, opt_mname, bufptr, size);
}

asn_enc_rval_t
CountryCode_encode_xer(asn_TYPE_descriptor_t *td, void *structure,
		int ilevel, enum xer_encoder_flags_e flags,
		asn_app_consume_bytes_f *cb, void *app_key) {
	CountryCode_1_inherit_TYPE_descriptor(td);
	return td->xer_encoder(td, structure, ilevel, flags, cb, app_key);
}

static const ber_tlv_tag_t asn_DEF_CountryCode_tags_1[] = {
	(ASN_TAG_CLASS_APPLICATION | (77 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (4 << 2))
};
asn_TYPE_descriptor_t asn_DEF_CountryCode = {
	"CountryCode",
	"CountryCode",
	CountryCode_free,
	CountryCode_print,
	CountryCode_constraint,
	CountryCode_decode_ber,
	CountryCode_encode_der,
	CountryCode_decode_xer,
	CountryCode_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_CountryCode_tags_1,
	sizeof(asn_DEF_CountryCode_tags_1)
		/sizeof(asn_DEF_CountryCode_tags_1[0]) - 1, /* 1 */
	asn_DEF_CountryCode_tags_1,	/* Same as above */
	sizeof(asn_DEF_CountryCode_tags_1)
		/sizeof(asn_DEF_CountryCode_tags_1[0]), /* 2 */
	0,	/* No PER visible constraints */
	0, 0,	/* No members */
	0	/* No specifics */
};

