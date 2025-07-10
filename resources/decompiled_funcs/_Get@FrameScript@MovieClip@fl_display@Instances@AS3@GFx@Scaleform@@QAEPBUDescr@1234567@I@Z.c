const Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr *__thiscall Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Get(
        Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript *this,
        unsigned int frameNum)
{
  unsigned int v2; // esi
  unsigned int FrameCnt; // ebp
  unsigned __int8 *v5; // ebx
  Scaleform::GFx::AS3::Value *Undefined; // eax
  const Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr *v7; // eax
  unsigned int v8; // edi
  const Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr *result; // eax
  Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr v10; // [esp+10h] [ebp-18h] BYREF

  v2 = frameNum;
  FrameCnt = this->FrameCnt;
  if ( frameNum >= FrameCnt || ((unsigned __int8)(1 << (frameNum & 7)) & this->pData[frameNum >> 3]) == 0 )
    return 0;
  v5 = &this->pData[4 * ((int)(FrameCnt + 31) / 32)];
  frameNum = (unsigned int)v5;
  Undefined = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetUndefined();
  Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr::Descr(&v10, v2, Undefined);
  v8 = Scaleform::Alg::LowerBoundSliced<Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr const *,Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr,bool (__cdecl *)(Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr const &,Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr const &)>(
         (const Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr *const *)&frameNum,
         0,
         this->DescrCnt,
         v7,
         (bool (__cdecl *)(const Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr *, const Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr *))Scaleform::Alg::OperatorLess<Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr>::Compare);
  if ( (v10.Method.Flags & 0x1F) > 9 )
  {
    if ( (v10.Method.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v10.Method);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v10.Method);
  }
  result = (const Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr *)&v5[24 * v8];
  if ( result->Frame != v2 )
    return 0;
  return result;
}
