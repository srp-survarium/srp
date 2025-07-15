void __thiscall Scaleform::GFx::AS3::AvmDisplayObj::InitClassName(
        Scaleform::GFx::AS3::AvmDisplayObj *this,
        char *className)
{
  unsigned int v3; // kr00_4
  unsigned __int8 *v4; // edi

  if ( !this->pClassName )
  {
    v3 = strlen(className);
    v4 = (unsigned __int8 *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                              Scaleform::Memory::pGlobalHeap,
                              this->pDispObj,
                              v3 + 1,
                              0);
    memcpy(v4, (unsigned __int8 *)className, v3 + 1);
    this->pClassName = (const char *)v4;
  }
}
