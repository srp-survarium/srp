threadlocaleinfostruct *__usercall updatetlocinfoEx_nolock@<eax>(
        threadlocaleinfostruct **pptlocid@<eax>,
        threadlocaleinfostruct *ptlocis@<edi>)
{
  threadlocaleinfostruct *v2; // esi

  if ( !ptlocis || !pptlocid )
    return 0;
  v2 = *pptlocid;
  if ( *pptlocid != ptlocis )
  {
    *pptlocid = ptlocis;
    __addlocaleref(ptlocis);
    if ( v2 )
    {
      __removelocaleref(v2);
      if ( !v2->refcount && v2 != &__initiallocinfo )
        __freetlocinfo(v2);
    }
  }
  return ptlocis;
}
