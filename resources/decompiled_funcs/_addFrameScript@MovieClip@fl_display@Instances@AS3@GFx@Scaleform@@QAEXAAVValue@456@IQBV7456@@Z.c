void __thiscall Scaleform::GFx::AS3::Instances::fl_display::MovieClip::addFrameScript(
        Scaleform::GFx::AS3::Instances::fl_display::MovieClip *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Instances::fl_display::MovieClip *v4; // edi
  unsigned int Size; // ebx
  Scaleform::GFx::DisplayObject *v6; // esi
  Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr *Data; // ebp
  Scaleform::GFx::AS3::Value *v8; // edi
  Scaleform::GFx::AS3::Value *v9; // ecx
  int v10; // eax
  Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript *p_mFrameScript; // edi
  Scaleform::MemoryHeap *Heap; // eax
  unsigned int v13; // eax
  Scaleform::GFx::InteractiveObject *pDispObj; // ecx
  unsigned int v15; // [esp-10h] [ebp-50h]
  unsigned int v16; // [esp-Ch] [ebp-4Ch]
  Scaleform::GFx::AS3::AvmSprite *avmSpr; // [esp+Ch] [ebp-34h]
  int frameNum; // [esp+10h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::Instances::fl_display::MovieClip *v19; // [esp+14h] [ebp-2Ch]
  int n; // [esp+18h] [ebp-28h]
  Scaleform::ArrayCPP<Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr,2,Scaleform::ArrayDefaultPolicy> frames; // [esp+1Ch] [ebp-24h] BYREF
  Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr fr; // [esp+28h] [ebp-18h] BYREF

  v4 = this;
  Size = 0;
  v19 = this;
  if ( !this->pDispObj.pObject )
    this->CreateStageObject(this);
  v6 = (v4->pDispObj.pObject->Flags & 0x400) != 0 ? v4->pDispObj.pObject : 0;
  if ( v6 )
  {
    avmSpr = (Scaleform::GFx::AS3::AvmSprite *)(&v6->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                              + v6->AvmObjOffset);
    Data = 0;
    n = argc >> 1;
    memset(&frames, 0, sizeof(frames));
    if ( argc >> 1 )
    {
      v8 = argv;
      argv = (Scaleform::GFx::AS3::Value *)(argc >> 1);
      do
      {
        v9 = v8++;
        if ( Scaleform::GFx::AS3::Value::Convert2Int32(v9, (Scaleform::GFx::AS3::CheckResult *)&argc, &frameNum)->Result )
        {
          Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr::Descr(&fr, frameNum, v8++);
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr,Scaleform::AllocatorGH_CPP<Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
            &frames.Data,
            &frames,
            Size + 1);
          Size = frames.Data.Size;
          Data = frames.Data.Data;
          if ( &frames.Data.Data[frames.Data.Size] != (Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr *)24 )
            Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr::Descr(
              &frames.Data.Data[frames.Data.Size - 1],
              &fr);
          if ( (fr.Method.Flags & 0x1F) > 9 )
          {
            if ( (fr.Method.Flags & 0x200) != 0 )
              Scaleform::GFx::AS3::Value::ReleaseWeakRef(&fr.Method);
            else
              Scaleform::GFx::AS3::Value::ReleaseInternal(&fr.Method);
          }
        }
        argv = (Scaleform::GFx::AS3::Value *)((char *)argv - 1);
      }
      while ( argv );
      v4 = v19;
    }
    v10 = (*(int (__thiscall **)(Scaleform::GFx::CharacterHandle *))(v6[1].pNameHandle.pObject->RefCount + 40))(v6[1].pNameHandle.pObject);
    v16 = n;
    v15 = v10;
    p_mFrameScript = &v4->mFrameScript;
    Heap = Scaleform::GFx::AS3::AvmDisplayObj::GetHeap(avmSpr);
    Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Set(p_mFrameScript, Heap, v15, v16, Data);
    v13 = ((int (__thiscall *)(Scaleform::GFx::DisplayObject *))v6->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable[1].GetY)(v6);
    if ( Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Get(p_mFrameScript, v13) )
    {
      pDispObj = (Scaleform::GFx::InteractiveObject *)avmSpr->pDispObj;
      avmSpr->Flags |= 2u;
      if ( Scaleform::GFx::InteractiveObject::IsInPlayList(pDispObj) )
        Scaleform::GFx::InteractiveObject::AddToOptimizedPlayList((Scaleform::GFx::InteractiveObject *)avmSpr->pDispObj);
    }
    Scaleform::ConstructorCPP<Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr>::DestructArray(
      Data,
      Size);
    if ( Data )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, Data);
  }
}
