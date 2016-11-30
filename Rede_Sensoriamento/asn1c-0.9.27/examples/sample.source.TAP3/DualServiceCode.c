/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0310"
 * 	found in "../tap3.asn1"
 * 	`asn1c -S ../../skeletons`
 */

#include "DualServiceCode.h"

static asn_TYPE_member_t asn_MBR_DualServiceCode_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct DualServiceCode, choice.dualTeleServiceCode),
		(ASN_TAG_CLASS_APPLICATION | (100 << 2)),
		0,
		&asn_DEF_DualTeleServiceCode,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"dualTeleServiceCode"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct DualServiceCode, choice.dualBearerServiceCode),
		(ASN_TAG_CLASS_APPLICATION | (99 << 2)),
		0,
		&asn_DEF_DualBearerServiceCode,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"dualBearerServiceCode"
		},
};
static const asn_TYPE_tag2member_t asn_MAP_DualServiceCode_tag2el_1[] = {
    { (ASN_TAG_CLASS_APPLICATION | (99 << 2)), 1, 0, 0 }, /* dualBearerServiceCode */
    { (ASN_TAG_CLASS_APPLICATION | (100 << 2)), 0, 0, 0 } /* dualTeleServiceCode */
};
static asn_CHOICE_specifics_t asn_SPC_DualServiceCode_specs_1 = {
	sizeof(struct DualServiceCode),
	offsetof(struct DualServiceCode, _asn_ctx),
	offsetof(struct DualServiceCode, present),
	sizeof(((struct DualServiceCode *)0)->present),
	asn_MAP_DualServiceCode_tag2el_1,
	2,	/* Count of tags in the map */
	0,
	-1	/* Extensions start */
};
asn_TYPE_descriptor_t asn_DEF_DualServiceCode = {
	"DualServiceCode",
	"DualServiceCode",
	CHOICE_free,
	CHOICE_print,
	CHOICE_constraint,
	CHOICE_decode_ber,
	CHOICE_encode_der,
	CHOICE_decode_xer,
	CHOICE_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	CHOICE_outmost_tag,
	0,	/* No effective tags (pointer) */
	0,	/* No effective tags (count) */
	0,	/* No tags (pointer) */
	0,	/* No tags (count) */
	0,	/* No PER visible constraints */
	asn_MBR_DualServiceCode_1,
	2,	/* Elements count */
	&asn_SPC_DualServiceCode_specs_1	/* Additional specs */
};
