void __thiscall Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Clear(
        Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript *this)
{
  unsigned __int8 *pData; // ecx
  Scaleform::GFx::AS3::Value *v3; // edi
  unsigned int i; // ebx

  pData = this->pData;
  if ( pData )
  {
    v3 = (Scaleform::GFx::AS3::Value *)&pData[4 * ((this->FrameCnt + 31) / 32)];
    for ( i = 0; i < this->DescrCnt; v3 = (Scaleform::GFx::AS3::Value *)((char *)v3 + 24) )
    {
      if ( (v3->Flags & 0x1F) > 9 )
      {
        if ( (v3->Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(v3);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(v3);
      }
      ++i;
    }
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->pData);
    this->pData = 0;
  }
}
