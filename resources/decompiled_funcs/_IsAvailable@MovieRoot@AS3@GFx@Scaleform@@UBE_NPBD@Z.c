char __thiscall Scaleform::GFx::AS3::MovieRoot::IsAvailable(
        Scaleform::GFx::AS3::MovieRoot *this,
        const char *ppathToVar)
{
  char ASVariableAtPath; // bl
  void *pWeakProxy; // eax
  Scaleform::GFx::AS3::Value resolvedVal; // [esp+4h] [ebp-10h] BYREF

  resolvedVal.Flags = 0;
  resolvedVal.Bonus.pWeakProxy = 0;
  ASVariableAtPath = Scaleform::GFx::AS3::MovieRoot::GetASVariableAtPath(this, &resolvedVal, ppathToVar);
  if ( (resolvedVal.Flags & 0x1F) > 9 )
  {
    if ( (resolvedVal.Flags & 0x200) != 0 )
    {
      pWeakProxy = resolvedVal.Bonus.pWeakProxy;
      if ( resolvedVal.Bonus.pWeakProxy->RefCount-- == 1 )
      {
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
        return ASVariableAtPath;
      }
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&resolvedVal);
    }
  }
  return ASVariableAtPath;
}
