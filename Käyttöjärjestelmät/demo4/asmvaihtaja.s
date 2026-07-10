        .text
        .global vaihda

# ------------------------------------------------------------------------------
# Aliohjelma "vaihda".
# Täydennä tämä sellaiseksi, että C-kielestä voidaan kutsua otsikon mukaan:
#
#   /** Vaihtaa muistissa osoitteissa "pa" ja "pb" olevat luvut keskenään. */
#   void vaihda(int64_t *pa, int64_t *pb);
#
# ------------------------------------------------------------------------------

vaihda:
	movq (%rdi), %rax	;
	movq (%rsi), %rdx	;
	movq %rdx, (%rdi)	;
	movq %rax, (%rsi)	;
	ret
