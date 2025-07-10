int __cdecl asn1_GetSequence(asn1_const_ctx_st *c, unsigned __int8 **length)
{
  const unsigned __int8 *p; // edi
  int object; // eax
  unsigned __int8 *v5; // ebx

  p = c->p;
  object = ASN1_get_object(&c->p, &c->slen, &c->tag, &c->xclass, *length);
  c->inf = object;
  if ( (object & 0x80u) == 0 )
  {
    if ( c->tag == 16 )
    {
      *length = &(*length)[p - c->p];
      v5 = *length;
      if ( c->max && (int)v5 < 0 )
      {
        c->error = 62;
        return 0;
      }
      else
      {
        if ( c->inf == 33 )
          c->slen = (int)&v5[*c->pp - c->p];
        c->eos = 0;
        return 1;
      }
    }
    else
    {
      c->error = 61;
      return 0;
    }
  }
  else
  {
    c->error = 60;
    return 0;
  }
}
