#include "../inst/include/Biostrings_defines.h"
#include <string.h>

#define DEBUG_BIOSTRINGS 1

#define CHRTRTABLE_LENGTH 256

typedef int CharToIntTable[CHRTRTABLE_LENGTH];


/* copy_seq.c */

SEXP debug_copy_seq();

void _copy_seq(
	char *dest,
	const char *src,
	size_t n,
	const int *chrtrtable
);

void _revcopy_seq(
	char *dest,
	const char *src,
	size_t n,
	const int *chrtrtable
);

void _copy_seq_from_i1i2(
	int i1, int i2,
	char *dest, int dest_length,
	const char *src, int src_length,
	const int *chrtrtable
);

void _copy_seq_to_i1i2(
	int i1, int i2,
	char *dest, int dest_length,
	const char *src, int src_length,
	const int *chrtrtable
);

void _copy_seq_from_subset(
	const int *subset, int n,
	char *dest, int dest_length,
	const char *src, int src_length,
	const int *chrtrtable
);

void _copy_seq_to_subset(
	const int *subset, int n,
	char *dest, int dest_length,
	const char *src, int src_length,
	const int *chrtrtable
);


/* utils.c */

SEXP debug_utils();

SEXP Biostrings_length_vectors_in_list(SEXP list);

char *_Biostrings_alloc_string(int n);

const char *_RoSeq2str(const RoSeq *seq);

int _Biostrings_memcmp(
	const char *a,
	int ia,
	const char *b,
	int ib,
	int n,
	size_t size
);

void _Biostrings_memcpy_from_i1i2(
	int i1,
	int i2,
	char *dest,
	size_t dest_nmemb,
	const char *src,
	size_t src_nmemb,
	size_t size
);

void _Biostrings_memcpy_from_subset(
	const int *subset,
	int n,
	char *dest,
	size_t dest_nmemb,
	const char *src,
	size_t src_nmemb,
	size_t size
);

void _Biostrings_memcpy_to_i1i2(
	int i1,
	int i2,
	char *dest,
	size_t dest_nmemb,
	const char *src,
	size_t src_nmemb,
	size_t size
);

void _Biostrings_memcpy_to_subset(
	const int *subset,
	int n,
	char *dest,
	size_t dest_nmemb,
	const char *src,
	size_t src_nmemb,
	size_t size
);

void _Biostrings_translate_charcpy_from_i1i2(
	int i1,
	int i2,
	char *dest,
	int dest_length,
	const char *src,
	int src_length,
	const int *lkup,
	int lkup_length
);

void _Biostrings_translate_charcpy_from_subset(
	const int *subset,
	int n,
	char *dest,
	int dest_length,
	const char *src,
	int src_length,
	const int *lkup,
	int lkup_length
);

void _Biostrings_translate_charcpy_to_i1i2(
	int i1,
	int i2,
	char *dest,
	int dest_length,
	const char *src,
	int src_length,
	const int *lkup,
	int lkup_length
);

void _Biostrings_translate_charcpy_to_subset(
	const int *subset,
	int n,
	char *dest,
	int dest_length,
	const char *src,
	int src_length,
	const int *lkup,
	int lkup_length
);

void _Biostrings_reverse_memcpy_from_i1i2(
	int i1,
	int i2,
	char *dest,
	size_t dest_nmemb,
	const char *src,
	size_t src_nmemb,
	size_t size
);

void _Biostrings_reverse_translate_charcpy_from_i1i2(
	int i1,
	int i2,
	char *dest,
	int dest_length,
	const char *src,
	int src_length,
	const int *lkup,
	int lkup_length
);

void _Biostrings_coerce_to_complex_from_i1i2(
	int i1,
	int i2,
	Rcomplex *dest,
	int dest_length,
	const char *src,
	int src_length,
	const Rcomplex *lkup,
	int lkup_length
);

int fgets_rtrimmed(
	char *s,
	int size,
	FILE *stream
);

void get_intorder(
	int len,
	const int *in,
	int *out
);

void _init_chrtrtable(
	const int *codes,
	int len,
	int *chrtrtable
);

void _normargs_startend(
	int *start,
	int *end,
	int width,
	const char *prefix
);


/* RoSeq_utils.c */

SEXP debug_RoSeq_utils();

SEXP _new_IRanges_from_RoSeqs(
	const char *class,
	const RoSeqs *seqs
);


/* Dups_utils.c */

SEXP debug_Dups_utils();

SEXP Dups_diff(
	SEXP x_unq2dup,
	SEXP y_dup2unq
);

void _init_dup2unq_buf(int length);

void _report_dup(
	int poffset,
	int P_id
);

SEXP _dup2unq_asINTEGER();


/* SparseList_utils.c */

SEXP debug_SparseList_utils();

SEXP _SparseList_int2symb(int symb_as_int);

int _SparseList_symb2int(SEXP symbol);

SEXP _get_val_from_env(
	SEXP symbol,
	SEXP env,
	int error_on_unbound_value
);

SEXP _get_val_from_SparseList(
	int symb_as_int,
	SEXP env,
	int error_on_unbound_value
);

int _get_int_from_SparseList(
	int symb_as_int,
	SEXP env
);

void _set_env_from_IntAE(
	SEXP env,
	const IntAE *int_ae
);

void _set_env_from_IntAEAE(
	SEXP env,
	const IntAEAE *int_aeae
);


/* XRaw_class.c */

SEXP debug_XRaw_class();

const char *_get_class(SEXP x);

SEXP Biostrings_safe_explode(SEXP s);

SEXP Biostrings_xp_new();

SEXP Biostrings_XRaw_alloc(
	SEXP xraw_xp,
	SEXP length
);

SEXP _get_XRaw_tag(SEXP x);

int _get_XRaw_length(SEXP x);

SEXP Biostrings_XRaw_get_show_string(SEXP xraw_xp);

SEXP Biostrings_XRaw_length(SEXP xraw_xp);

SEXP _new_XRaw(SEXP tag);

SEXP _new_XRaw_from_RoSeqs(
	const RoSeqs *seqs,
	SEXP lkup
);

void _write_RoSeq_to_XRaw(
	SEXP x,
	int offset,
	const RoSeq *seq,
	const int *chrtrtable
);

SEXP _new_CHARSXP_from_RoSeq(
	const RoSeq *seq,
	SEXP lkup
);

SEXP _new_STRSXP_from_RoSeqs(
	const RoSeqs *seqs,
	SEXP lkup
);


/* XRaw_utils.c */

SEXP debug_XRaw_utils();

SEXP Biostrings_XRaw_memcmp(
	SEXP xraw1_xp,
	SEXP start1,
	SEXP xraw2_xp,
	SEXP start2,
	SEXP width
);

SEXP Biostrings_XRaw_memcpy(
	SEXP dest_xraw_xp,
	SEXP dest_start,
	SEXP src_xraw_xp,
	SEXP src_start,
	SEXP width
);

SEXP Biostrings_XRaw_copy_from_i1i2(
	SEXP dest_xraw_xp,
	SEXP src_xraw_xp,
	SEXP imin,
	SEXP imax
);

SEXP Biostrings_XRaw_copy_from_subset(
	SEXP dest_xraw_xp,
	SEXP src_xraw_xp,
	SEXP subset
);

SEXP Biostrings_XRaw_read_chars_from_i1i2(
	SEXP src_xraw_xp,
	SEXP imin,
	SEXP imax
);

SEXP Biostrings_XRaw_read_chars_from_subset(
	SEXP src_xraw_xp,
	SEXP subset
);

SEXP Biostrings_XRaw_write_chars_to_i1i2(
	SEXP dest_xraw_xp,
	SEXP imin,
	SEXP imax,
	SEXP string
);

SEXP Biostrings_XRaw_write_chars_to_subset(
	SEXP dest_xraw_xp,
	SEXP subset,
	SEXP string
);

SEXP XRaw_read_ints_from_i1i2(
	SEXP src_xraw_xp,
	SEXP imin,
	SEXP imax
);

SEXP XRaw_read_ints_from_subset(
	SEXP src_xraw_xp,
	SEXP subset
);

SEXP XRaw_write_ints_to_i1i2(
	SEXP dest_xraw_xp,
	SEXP imin,
	SEXP imax,
	SEXP val
);

SEXP XRaw_write_ints_to_subset(
	SEXP dest_xraw_xp,
	SEXP subset,
	SEXP val
);

SEXP XRaw_read_enc_chars_from_i1i2(
	SEXP src_xraw_xp,
	SEXP imin,
	SEXP imax,
	SEXP lkup
);

SEXP XRaw_read_enc_chars_from_subset(
	SEXP src_xraw_xp,
	SEXP subset,
	SEXP lkup
);

SEXP XRaw_write_enc_chars_to_i1i2(
	SEXP dest_xraw_xp,
	SEXP imin,
	SEXP imax,
	SEXP string,
	SEXP lkup
);

SEXP XRaw_write_enc_chars_to_subset(
	SEXP dest_xraw_xp,
	SEXP subset,
	SEXP string,
	SEXP lkup
);

SEXP XRaw_read_complexes_from_i1i2(
	SEXP src_xraw_xp,
	SEXP imin,
	SEXP imax,
	SEXP lkup
);

SEXP XRaw_read_complexes_from_subset(
	SEXP src_xraw_xp,
	SEXP subset,
	SEXP lkup
);

SEXP XRaw_loadFASTA(
	SEXP xraw_xp,
	SEXP filepath,
	SEXP collapse,
	SEXP lkup
);


/* XString_class.c */

SEXP debug_XString_class();

const int *get_enc_chrtrtable(const char *class);

const int *get_dec_chrtrtable(const char *class);

SEXP init_DNAlkups(SEXP enc_lkup, SEXP dec_lkup);

char _DNAencode(char c);

char _DNAdecode(char code);

SEXP init_RNAlkups(SEXP enc_lkup, SEXP dec_lkup);

char _RNAencode(char c);

char _RNAdecode(char code);

SEXP _get_XString_xdata(SEXP x);

RoSeq _get_XString_asRoSeq(SEXP x);

SEXP _new_XString(
	const char *class,
	SEXP xdata,
	int offset,
	int length
);

SEXP _new_XString_from_RoSeqs(
	const char *class,
	const RoSeqs *seqs
);

SEXP _alloc_XString(
	const char *class,
	int length
);

void _write_RoSeq_to_XString(
	SEXP x,
	int start,
	const RoSeq *seq,
	int encode
);


/* XStringSet_class.c */

SEXP debug_XStringSet_class();

const char *_get_XStringSet_baseClass(SEXP x);

int _get_XStringSet_length(SEXP x);

CachedXStringSet _new_CachedXStringSet(SEXP x);

RoSeq _get_CachedXStringSet_elt_asRoSeq(
	CachedXStringSet *x,
	int i
);

RoSeq _get_XStringSet_elt_asRoSeq(
	SEXP x,
	int i
);

SEXP _new_XStringSet_from_RoSeqs(
	const char *baseClass,
	const RoSeqs *seqs
);

void _set_XStringSet_names(
	SEXP x,
	SEXP names
);

SEXP _alloc_XStringSet(
	const char *baseClass,
	int length,
	int super_length
);

void _write_RoSeq_to_CachedXStringSet_elt(
	CachedXStringSet *x,
	int i,
	const RoSeq *seq,
	int encode
);

void _write_RoSeq_to_XStringSet_elt(
	SEXP x,
	int i,
	const RoSeq *seq,
	int encode
);

SEXP XStringSet_as_STRSXP(
	SEXP x,
	SEXP lkup
);


/* seqs_to_seqs.c */

SEXP debug_seqs_to_seqs();

RoSeqs _new_RoSeqs_from_CharAEAE(const CharAEAE *char_aeae);

RoSeqs _new_RoSeqs_from_STRSXP(
	int nseq,
	SEXP x
);

RoSeqs _new_RoSeqs_from_XString(
	int nseq,
	SEXP x
);

RoSeqs _new_RoSeqs_from_XStringSet(
	int nseq,
	SEXP x
);

SEXP copy_subXRaw(
	SEXP x,
	SEXP start,
	SEXP nchar,
	SEXP lkup
);

SEXP new_XRaw_from_STRSXP(
	SEXP x,
	SEXP safe_starts,
	SEXP safe_widths,
	SEXP collapse,
	SEXP lkup
);

SEXP new_XRaw_from_XString(
	SEXP x,
	SEXP safe_starts,
	SEXP safe_widths,
	SEXP lkup
);


/* char_frequency.c */

SEXP XString_char_frequency(
	SEXP x,
	SEXP codes,
	SEXP with_other
);

SEXP XStringSet_char_frequency(
	SEXP x,
	SEXP codes,
	SEXP with_other,
	SEXP collapse
);

SEXP oligonucleotide_frequency(
	SEXP x,
	SEXP base_codes,
	SEXP width,
	SEXP fast_moving_side
);


/* char_translate.c */

SEXP XRaw_translate_copy_from_i1i2(
	SEXP dest_xraw_xp,
	SEXP src_xraw_xp,
	SEXP imin,
	SEXP imax,
	SEXP lkup
);

SEXP XRaw_translate_copy_from_subset(
	SEXP dest_xraw_xp,
	SEXP src_xraw_xp,
	SEXP subset,
	SEXP lkup
);

SEXP XRaw_reverse_copy_from_i1i2(
	SEXP dest_xraw_xp,
	SEXP src_xraw_xp,
	SEXP imin,
	SEXP imax
);

SEXP XRaw_reverse_translate_copy_from_i1i2(
	SEXP dest_xraw_xp,
	SEXP src_xraw_xp,
	SEXP imin,
	SEXP imax,
	SEXP lkup
);

SEXP XStringSet_char_translate(
	SEXP x,
	SEXP lkup,
	SEXP reverse
);


/* replace_locs.c */

SEXP XString_replace_locs_bySTRSXP(
	SEXP x,
	SEXP loc,
	SEXP letter,
	SEXP lkup,
	SEXP if_not_extending,
	SEXP verbose
);

SEXP XString_inplace_replace_locs_bySTRSXP(
	SEXP x,
	SEXP loc,
	SEXP letter,
	SEXP lkup
);


/* inject_code.c */

SEXP inject_code(
	SEXP x,
	SEXP safe_starts,
	SEXP safe_widths,
	SEXP code
);


/* match_utils.c */

SEXP debug_match_utils();

int (*_selected_nmismatch_at_Pshift_fun)(
	const RoSeq *P,
	const RoSeq *S,
	int Pshift,
	int max_mm
);

void _select_nmismatch_at_Pshift_fun(
	int fixedP,
	int fixedS
);

SEXP nmismatch_at(
	SEXP pattern,
	SEXP subject,
	SEXP starting,
	SEXP at,
	SEXP fixed
);

SEXP is_matching(
	SEXP pattern,
	SEXP subject,
	SEXP start,
	SEXP max_mismatch,
	SEXP fixed
);

SEXP nmatch_PairwiseAlignment(
	SEXP nchar,
	SEXP nmismatch,
	SEXP ninsertion,
	SEXP ndeletion
);


/* match_reporting.c */

SEXP debug_match_reporting();

void _init_match_reporting(int mrmode);

void _drop_current_matches();

void _set_match_shift(int shift);

int _report_view(
	int start,
	int end,
	const char *name
);

int _report_match(
	int start,
	int end
);

SEXP _reported_match_count_asINTEGER();

SEXP _reported_match_starts_asINTEGER();

SEXP _reported_match_ends_asINTEGER();

SEXP _reported_view_names_asCHARACTER();

SEXP _reported_matches_asLIST();

SEXP _reported_matches_asSEXP();


/* match_pattern_boyermoore.c */

SEXP debug_match_pattern_boyermoore();

void _match_pattern_boyermoore(
	const RoSeq *P,
	const RoSeq *S
);


/* match_pattern_shiftor.c */

SEXP debug_match_pattern_shiftor();

SEXP bits_per_long();

void _match_pattern_shiftor(
	const RoSeq *P,
	const RoSeq *S,
	int max_mm,
	int fixedP,
	int fixedS
);


/* match_pattern.c */

SEXP debug_match_pattern();

SEXP XString_match_pattern(
	SEXP pattern,
	SEXP subject,
	SEXP algorithm,
	SEXP max_mismatch,
	SEXP fixed,
	SEXP count_only
);

SEXP XStringViews_match_pattern(
	SEXP pattern,
	SEXP subject,
	SEXP views_start,
	SEXP views_width,
	SEXP algorithm,
	SEXP max_mismatch,
	SEXP fixed,
	SEXP count_only
);

SEXP XStringSet_vmatch_pattern(
	SEXP pattern,
	SEXP subject,
	SEXP algorithm,
	SEXP max_mismatch,
	SEXP fixed,
	SEXP count_only
);


/* match_BOC.c */

SEXP debug_match_BOC();

SEXP match_BOC_preprocess(
	SEXP s_xp,
	SEXP s_offset,
	SEXP s_length,
	SEXP p_length,
	SEXP code1,
	SEXP code2,
	SEXP code3,
	SEXP code4,
	SEXP buf1_xp,
	SEXP buf2_xp,
	SEXP buf3_xp,
	SEXP pre4buf_xp
);

SEXP match_BOC_exact(
	SEXP p_xp,
	SEXP p_offset,
	SEXP p_length,
	SEXP s_xp,
	SEXP s_offset,
	SEXP s_length,
	SEXP code1,
	SEXP code2,
	SEXP code3,
	SEXP code4,
	SEXP buf1_xp,
	SEXP buf2_xp,
	SEXP buf3_xp,
	SEXP pre4buf_xp,
	SEXP stats,
	SEXP count_only
);


/* match_BOC2.c */

SEXP debug_match_BOC2();

SEXP match_BOC2_preprocess(
	SEXP s_xp,
	SEXP s_offset,
	SEXP s_length,
	SEXP p_length,
	SEXP code1,
	SEXP code2,
	SEXP code3,
	SEXP code4,
	SEXP buf_xp
);

SEXP match_BOC2_exact(
	SEXP p_xp,
	SEXP p_offset,
	SEXP p_length,
	SEXP s_xp,
	SEXP s_offset,
	SEXP s_length,
	SEXP code1,
	SEXP code2,
	SEXP code3,
	SEXP code4,
	SEXP buf_xp,
	SEXP stats,
	SEXP count_only
);


/* match_PWM.c */

SEXP PWM_score(
	SEXP pwm,
	SEXP subject,
	SEXP start
);

SEXP match_PWM(
	SEXP pwm,
	SEXP subject,
	SEXP min_score,
	SEXP count_only
);


/* find_palindromes.c */

SEXP debug_find_palindromes();

SEXP find_palindromes(
	SEXP s_xp,
	SEXP s_offset,
	SEXP s_length,
	SEXP min_armlength,
	SEXP max_ngaps,
	SEXP L2R_lkup
);


/* MIndex_utils.c */

SEXP debug_MIndex_utils();

void _MIndex_init_match_reporting(
	int is_count_only,
	int with_headtail,
	int pdict_L
);

int _MIndex_get_match_reporting_mode();

IntAE *_MIndex_get_match_count();

IntAE *_MIndex_get_match_ends(int key);

IntAE *_MIndex_get_matching_keys();

void _MIndex_report_match(
	int key,
	int end
);

void _MIndex_merge_matches(
	IntAE *global_match_count,
	const IntAEAE *global_match_ends,
	int view_offset
);

SEXP _MIndex_reported_matches_asSEXP(SEXP env);

SEXP ByPos_MIndex_endIndex(
	SEXP x_dup2unq,
	SEXP x_ends,
	SEXP shift
);

SEXP ByName_MIndex_endIndex(
	SEXP ends_envir,
	SEXP shift,
	SEXP names,
	SEXP all_names
);

void ByPos_MIndex_coverage(
	SEXP ends_list,
	SEXP mindex_width,
	SEXP start,
	SEXP ans_xp
);

void ByName_MIndex_coverage(
	SEXP ends_envir,
	SEXP mindex_width,
	SEXP start,
	SEXP ans_xp
);

SEXP ByPos_MIndex_combine(SEXP ends_listlist);


/* match_pdict_Twobit.c */

SEXP debug_match_pdict_Twobit();

SEXP build_Twobit(
	SEXP tb,
	SEXP dup2unq0,
	SEXP base_codes
);

void _match_Twobit(
	SEXP pdict_pptb,
	const RoSeq *S,
	int fixedS
);


/* match_pdict_ACtree.c */

SEXP debug_match_pdict_ACtree();

SEXP free_actree_nodes_buf();

SEXP build_ACtree(
	SEXP tb,
	SEXP dup2unq0,
	SEXP base_codes
);

void _match_ACtree(
	SEXP pdict_pptb,
	const RoSeq *S,
	int fixedS
);


/* match_pdict.c */

SEXP debug_match_pdict();

SEXP XString_match_pdict(
	SEXP pdict_type,
	SEXP pdict_pptb,
	SEXP pdict_length,
	SEXP pdict_tb_width,
	SEXP pdict_tb_unq2dup,
	SEXP pdict_head,
	SEXP pdict_tail,
	SEXP subject,
	SEXP max_mismatch,
	SEXP fixed,
	SEXP count_only,
	SEXP envir
);

SEXP XStringViews_match_pdict(
	SEXP pdict_type,
	SEXP pdict_pptb,
	SEXP pdict_length,
	SEXP pdict_tb_width,
	SEXP pdict_tb_unq2dup,
	SEXP pdict_head,
	SEXP pdict_tail,
	SEXP subject,
	SEXP views_start,
	SEXP views_width,
	SEXP max_mismatch,
	SEXP fixed,
	SEXP count_only,
	SEXP envir
);


/* pmatchPattern.c */

SEXP lcprefix(
	SEXP s1_xp,
	SEXP s1_offset,
	SEXP s1_length,
	SEXP s2_xp,
	SEXP s2_offset,
	SEXP s2_length
);

SEXP lcsuffix(
	SEXP s1_xp,
	SEXP s1_offset,
	SEXP s1_length,
	SEXP s2_xp,
	SEXP s2_offset,
	SEXP s2_length
);


/* align_needwunsQS.c */

SEXP align_needwunsQS(
	SEXP s1,
	SEXP s2,
	SEXP mat,
	SEXP mat_nrow,
	SEXP lkup,
	SEXP gap_cost,
	SEXP gap_code
);


/* align_pairwiseAlignment.c */

SEXP XStringSet_align_pairwiseAlignment(
	SEXP pattern,
	SEXP subject,
	SEXP patternQuality,
	SEXP subjectQuality,
	SEXP type,
	SEXP typeCode,
	SEXP qualityType,
	SEXP scoreOnly,
	SEXP gapOpening,
	SEXP gapExtension,
	SEXP useQuality,
	SEXP qualityLookupTable,
	SEXP qualityMatchMatrix,
	SEXP qualityMismatchMatrix,
	SEXP qualityMatrixDim,
	SEXP constantLookupTable,
	SEXP constantMatrix,
	SEXP constantMatrixDim
);

SEXP XStringSet_align_distance(
	SEXP string,
	SEXP stringQuality,
	SEXP type,
	SEXP typeCode,
	SEXP gapOpening,
	SEXP gapExtension,
	SEXP useQuality,
	SEXP qualityLookupTable,
	SEXP qualityMatchMatrix,
	SEXP qualityMismatchMatrix,
	SEXP qualityMatrixDim,
	SEXP constantLookupTable,
	SEXP constantMatrix,
	SEXP constantMatrixDim
);


/* align_utils.c */

SEXP AlignedXStringSet_nchar(SEXP alignedXStringSet);
SEXP AlignedXStringSet_align_aligned(SEXP alignedXStringSet, SEXP gapCode);
SEXP align_compareStrings(SEXP patternStrings, SEXP subjectStrings, SEXP maxNChar,
                          SEXP insertionCode, SEXP deletionCode, SEXP mismatchCode);
