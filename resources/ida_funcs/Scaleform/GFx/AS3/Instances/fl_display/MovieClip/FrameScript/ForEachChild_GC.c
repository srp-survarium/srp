void __thiscall Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::ForEachChild_GC(
        Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__cdecl *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, const Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  unsigned __int8 *pData; // ecx
  const Scaleform::GFx::AS3::Value *v5; // esi
  unsigned int i; // ebx

  pData = this->pData;
  if ( pData )
  {
    v5 = (const Scaleform::GFx::AS3::Value *)&pData[4 * ((this->FrameCnt + 31) / 32)];
    for ( i = 0; i < this->DescrCnt; v5 = (const Scaleform::GFx::AS3::Value *)((char *)v5 + 24) )
    {
      if ( (v5->Flags & 0x1F) > 0xA && (v5->Flags & 0x200) == 0 )
        Scaleform::GFx::AS3::ForEachChild_GC_Internal(prcc, v5, op);
      ++i;
    }
  }
}
