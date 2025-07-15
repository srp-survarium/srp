int __usercall vorbis_book_init_encode@<eax>(codebook *c@<edi>, const static_codebook *s@<eax>)
{
  int q_min; // ecx
  long double x; // st7
  int q_delta; // esi
  long double v6; // st7
  float v8; // [esp+14h] [ebp-4h]
  float v9; // [esp+14h] [ebp-4h]

  memset((int)c, 0, sizeof(codebook));
  c->c = s;
  c->entries = s->entries;
  c->used_entries = s->entries;
  c->dim = s->dim;
  c->codelist = _make_words(s->lengthlist, s->entries, 0);
  c->quantvals = _book_maptype1_quantvals(s);
  q_min = s->q_min;
  x = (double)(int)(((unsigned int)&loc_1FFFFE + 1) & q_min);
  if ( q_min < 0 )
    x = -x;
  v8 = ldexp(x, ((s->q_min >> 21) & 0x3FFu) - 788);
  c->minval = (int)floor(v8 + 0.5);
  q_delta = s->q_delta;
  v6 = (double)(int)(((unsigned int)&loc_1FFFFE + 1) & q_delta);
  if ( q_delta < 0 )
    v6 = -v6;
  v9 = ldexp(v6, ((q_delta >> 21) & 0x3FFu) - 788);
  c->delta = (int)floor(v9 + 0.5);
  return 0;
}
