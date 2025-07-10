void __cdecl Scaleform::GFx::AS3::RefCountBaseGC<328>::ScanTempInUseCall(
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        const Scaleform::GFx::AS3::RefCountBaseGC<328> **pchild)
{
  unsigned int v2; // eax

  v2 = (++(*pchild)->RefCount >> 28) & 7;
  if ( v2 != 5 )
  {
    if ( v2 )
    {
      (*pchild)->RefCount = (*pchild)->RefCount & 0x8FFFFFFF | 0x50000000;
      Scaleform::GFx::AS3::RefCountCollector<328>::ReinsertToList(prcc, *pchild);
    }
  }
}
