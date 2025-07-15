Scaleform::Ptr<Scaleform::GFx::ASIMEManager> *__thiscall Scaleform::GFx::AS2Support::CreateASIMEManager(
        Scaleform::GFx::AS2Support *this,
        Scaleform::Ptr<Scaleform::GFx::ASIMEManager> *result)
{
  Scaleform::GFx::AS2::IMEManager *v2; // eax
  Scaleform::GFx::ASIMEManager *v3; // eax
  Scaleform::Ptr<Scaleform::GFx::ASIMEManager> *v4; // eax

  v2 = (Scaleform::GFx::AS2::IMEManager *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 120, 0);
  if ( v2 )
  {
    Scaleform::GFx::AS2::IMEManager::IMEManager(v2);
    result->pObject = v3;
    return result;
  }
  else
  {
    v4 = result;
    result->pObject = 0;
  }
  return v4;
}
