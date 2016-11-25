/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0310"
 * 	found in "../tap3.asn1"
 * 	`asn1c -S ../../skeletons`
 */

#include "NonChargedParty.h"

static asn_TYPE_member_t asn_MBR_NonChargedParty_1[] = {
	{ ATF_POINTER, 2, offsetof(struct NonChargedParty, nonChargedNumber),
		(ASN_TAG_CLASS_APPLICATION | (33 << 2)),
		0,
		&asn_DEF_AddressStringDigits,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"nonChargedNumber"
		},
	{ ATF_POINTER, 1, offsetof(struct NonChargedParty, calledNumAnalysisCode),
		(ASN_TAG_CLASS_APPLICATION | (247 << 2)),
		0,
		&asn_DEF_CalledNumAnalysisCode,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"calledNumAnalysisCode"
		},
};
static const ber_tlv_tag_t asn_DEF_NonChargedParty_tags_1[] = {
	(ASN_TAG_CLASS_APPLICATION | (158 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_NonChargedParty_tag2el_1[] = {
    { (ASN_TAG_CLASS_APPLICATION | (33 << 2)), 0, 0, 0 }, /* nonChargedNumber */
    { (ASN_TAG_CLASS_APPLICATION | (247 << 2)), 1, 0, 0 } /* calledNumAnalysisCode */
};
static asn_SEQUENCE_specifics_t asn_SPC_NonChargedParty_specs_1 = {
	sizeof(struct NonChargedParty),
	offsetof(struct NonChargedParty, _asn_ctx),
	asn_MAP_NonChargedParty_tag2el_1,
	2,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_NonChargedParty = {
	"NonChargedParty",
	"NonChargedParty",
	SEQUENCE_free,
	SEQUENCE_print,
	SEQUENCE_constraint,
	SEQUENCE_decode_ber,
	SEQUENCE_encode_der,
	SEQUENCE_decode_xer,
	SEQUENCE_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_NonChargedParty_tags_1,
	sizeof(asn_DEF_NonChargedParty_tags_1)
		/sizeof(asn_DEF_NonChargedParty_tags_1[0]) - 1, /* 1 */
	asn_DEF_NonChargedParty_tags_1,	/* Same as above */
	sizeof(asn_DEF_NonChargedParty_tags_1)
		/sizeof(asn_DEF_NonChargedParty_tags_1[0]), /* 2 */
	0,	/* No PER visible constraints */
	asn_MBR_NonChargedParty_1,
	2,	/* Elements count */
	&asn_SPC_NonChargedParty_specs_1	/* Additional specs */
};

