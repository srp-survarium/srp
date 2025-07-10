void __userpurge Scaleform::GFx::AS3::AvmDisplayObj::FireEvent(
        Scaleform::GFx::AS3::AvmDisplayObj *this@<ecx>,
        int a2@<ebp>,
        const Scaleform::GFx::EventId *id)
{
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *pAS3RawPtr; // eax
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *v5; // ebx
  const Scaleform::GFx::EventId *v6; // edi
  unsigned int v7; // eax
  unsigned int v8; // eax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *AS3Parent; // ecx
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v10; // eax
  bool (__thiscall *CheckAvm)(Scaleform::GFx::ASMovieRootBase *); // edi
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject_vtbl *v12; // ebp
  const Scaleform::GFx::AS3::Value *v13; // eax
  const Scaleform::GFx::AS3::Multiname *v14; // eax
  Scaleform::GFx::AS3::VM *v15; // ecx
  Scaleform::GFx::ASStringNode *v16; // eax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v17; // eax
  const Scaleform::GFx::ASString *v18; // edi
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *v19; // ecx
  Scaleform::GFx::DisplayObject *pDispObj; // eax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *pObject; // eax
  const Scaleform::GFx::ASString *p_pMovieImpl; // edi
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *v23; // ebx
  unsigned int RefCount; // eax
  const Scaleform::GFx::AS3::Value *v25; // [esp-8h] [ebp-54h]
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *v26; // [esp+Ch] [ebp-40h]
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *v27; // [esp+Ch] [ebp-40h]
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *v28; // [esp+Ch] [ebp-40h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> evt; // [esp+10h] [ebp-3Ch] BYREF
  Scaleform::GFx::AS3::Value name; // [esp+14h] [ebp-38h] BYREF
  Scaleform::GFx::AS3::Value v31; // [esp+24h] [ebp-28h] BYREF
  Scaleform::GFx::AS3::Multiname v32; // [esp+34h] [ebp-18h] BYREF

  pAS3RawPtr = this->pAS3RawPtr;
  if ( !pAS3RawPtr )
    pAS3RawPtr = this->pAS3CollectiblePtr.pObject;
  v5 = pAS3RawPtr;
  v26 = pAS3RawPtr;
  if ( ((unsigned __int8)pAS3RawPtr & 1) != 0 )
  {
    v5 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)pAS3RawPtr - 1);
    v26 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)pAS3RawPtr - 1);
  }
  if ( v5 )
    v5->RefCount = (v5->RefCount + 1) & 0x8FBFFFFF;
  v6 = id;
  v7 = id->Id;
  if ( id->Id > (unsigned int)&vostok::memory::s_CRT_arena[5574215] )
  {
    switch ( v7 - (_DWORD)&vostok::memory::s_CRT_arena[5574216] )
    {
      case 0u:
        this->pDispObj->Depth = 0;
        pObject = this->pAS3RawPtr;
        p_pMovieImpl = (const Scaleform::GFx::ASString *)&this->pDispObj->pASRoot[15].pMovieImpl;
        if ( !pObject )
          pObject = this->pAS3CollectiblePtr.pObject;
        v23 = pObject;
        if ( ((unsigned __int8)pObject & 1) != 0 )
          v23 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)pObject - 1);
        if ( v23
          && Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::HasEventHandler(v23, p_pMovieImpl, 0)
          && !LOBYTE(Scaleform::GFx::AS3::AvmDisplayObj::GetAVM(this)->OnMovieFocus) )
        {
          Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::CreateEventObject(
            v23,
            (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&evt,
            p_pMovieImpl,
            1,
            0);
          Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
            (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&evt.pObject->Target,
            (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)v23);
          Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Dispatch(v23, evt.pObject, this->pDispObj);
          Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>::~SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>(&evt);
        }
        if ( (this->Flags & 1) != 0 && !LOBYTE(Scaleform::GFx::AS3::AvmDisplayObj::GetAVM(this)->OnMovieFocus) )
        {
          Scaleform::GFx::AS3::MovieRoot::CreateEventObject(
            (Scaleform::GFx::AS3::MovieRoot *)this->pDispObj->pASRoot,
            (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&evt,
            (const Scaleform::GFx::ASString *)&this->pDispObj->pASRoot[15].pASSupport,
            0,
            0);
          this->PropagateEvent(this, evt.pObject, 0);
          Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>::~SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>(&evt);
        }
        this->pDispObj->OnEventUnload(this->pDispObj);
        v5 = v26;
        break;
      case 1u:
        if ( !v5 )
          return;
        if ( (unsigned __int8)Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::MayHaveActivateHandler(v5) )
          goto LABEL_70;
        break;
      case 2u:
        if ( !v5 )
          return;
        if ( (unsigned __int8)Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::MayHaveDeactivateHandler(v5) )
          goto LABEL_70;
        break;
      case 3u:
        if ( !v5 )
          return;
        if ( (unsigned __int8)Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::MayHaveRenderHandler(v5) )
LABEL_70:
          Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Dispatch(v5, v6, this->pDispObj);
        break;
      case 4u:
        if ( v5 )
          goto LABEL_70;
        return;
      case 5u:
        if ( !v5 )
          return;
        if ( (unsigned __int8)Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::MayHaveFrameConstructedHandler(v5) )
          Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DispatchToTarget(
            v5,
            (const Scaleform::GFx::ASString *)&this->pDispObj->pASRoot[16].RefCount,
            (Scaleform::RefCountVImpl *)v5,
            0,
            this->pDispObj);
        break;
      case 6u:
        if ( !v5 )
          return;
        if ( (unsigned __int8)Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::MayHaveExitFrameHandler(v5) )
          Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DispatchToTarget(
            v5,
            (const Scaleform::GFx::ASString *)&this->pDispObj->pASRoot[16].pMovieImpl,
            (Scaleform::RefCountVImpl *)v5,
            0,
            this->pDispObj);
        break;
      default:
        break;
    }
  }
  else if ( (unsigned __int8 *)id->Id == &vostok::memory::s_CRT_arena[5574215] )
  {
    v17 = this->pAS3RawPtr;
    v18 = (const Scaleform::GFx::ASString *)&this->pDispObj->pASRoot[15];
    if ( !v17 )
      v17 = this->pAS3CollectiblePtr.pObject;
    v19 = v17;
    v28 = v17;
    if ( ((unsigned __int8)v17 & 1) != 0 )
    {
      v19 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v17 - 1);
      v28 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v17 - 1);
    }
    if ( v19
      && Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::HasEventHandler(v19, v18, 0)
      && !LOBYTE(Scaleform::GFx::AS3::AvmDisplayObj::GetAVM(this)->OnMovieFocus) )
    {
      Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::CreateEventObject(
        v28,
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&evt,
        v18,
        1,
        0);
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&evt.pObject->Target,
        (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)v28);
      Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Dispatch(v28, evt.pObject, this->pDispObj);
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>::~SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>(&evt);
    }
    if ( Scaleform::GFx::AS3::AvmDisplayObj::IsStageAccessible(this) )
    {
      this->pDispObj->pASRoot->CheckAvm(this->pDispObj->pASRoot);
      pDispObj = this->pDispObj;
      if ( !LOBYTE(pDispObj->pASRoot[2].OnMovieFocus) )
      {
        Scaleform::GFx::AS3::MovieRoot::CreateEventObject(
          (Scaleform::GFx::AS3::MovieRoot *)pDispObj->pASRoot,
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&evt,
          (const Scaleform::GFx::ASString *)&pDispObj->pASRoot[15].RefCount,
          0,
          0);
        this->PropagateEvent(this, evt.pObject, 0);
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>::~SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>(&evt);
      }
    }
  }
  else if ( v7 > 0x200 )
  {
    if ( v7 == 0x40000 )
      Scaleform::GFx::AS3::AvmDisplayObj::CallCtor(this, 1);
  }
  else if ( v7 == 512 )
  {
    if ( (this->pDispObj->Flags & 1) != 0 )
    {
      Scaleform::GFx::AS3::AvmDisplayObj::CreateASInstanceNoCtor(this, a2, (int)id);
      if ( (this->pDispObj->Flags & 2) == 0 )
      {
        if ( Scaleform::GFx::AS3::AvmDisplayObj::GetAS3Parent(this) )
        {
          Scaleform::GFx::DisplayObject::GetName(this->pDispObj, (Scaleform::GFx::ASString *)&evt);
          Scaleform::GFx::AS3::Value::Value(&name, (const Scaleform::GFx::ASString *)&evt);
          AS3Parent = Scaleform::GFx::AS3::AvmDisplayObj::GetAS3Parent(this);
          v10 = this->pAS3RawPtr;
          v27 = AS3Parent;
          if ( !v10 )
            v10 = this->pAS3CollectiblePtr.pObject;
          if ( ((unsigned __int8)v10 & 1) != 0 )
            v10 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v10 - 1);
          CheckAvm = this->pDispObj->pASRoot[2].__vftable[1].CheckAvm;
          v12 = AS3Parent->__vftable;
          Scaleform::GFx::AS3::Value::Value(&v31, v10);
          v25 = v13;
          Scaleform::GFx::AS3::Multiname::Multiname(
            &v32,
            (Scaleform::GFx::AS3::Instances::fl::Namespace *)CheckAvm,
            &name);
          v12->SetProperty(
            (struct Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)v27,
            (Scaleform::GFx::AS3::CheckResult *)&id,
            v14,
            v25);
          Scaleform::GFx::AS3::Multiname::~Multiname(&v32);
          Scaleform::GFx::AS3::Value::~Value(&v31);
          Scaleform::GFx::AS3::Value::~Value(&name);
          v15 = (Scaleform::GFx::AS3::VM *)this->pDispObj->pASRoot[2].__vftable;
          if ( v15->HandleException )
          {
            Scaleform::GFx::AS3::VM::OutputAndIgnoreException(v15);
            this->pDispObj->pParent->Flags |= 0x20u;
          }
          v16 = (Scaleform::GFx::ASStringNode *)evt.pObject;
          --evt.pObject->pPrev;
          if ( !v16->RefCount )
            Scaleform::GFx::ASStringNode::ReleaseNode(v16);
        }
      }
    }
  }
  else
  {
    v8 = v7 - 1;
    if ( v8 )
    {
      if ( v8 == 1 )
      {
        if ( !v5 )
          return;
        if ( (unsigned __int8)Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::MayHaveEnterFrameHandler(v5) )
          Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DispatchToTarget(
            v5,
            (const Scaleform::GFx::ASString *)&this->pDispObj->pASRoot[16],
            (Scaleform::RefCountVImpl *)v5,
            0,
            this->pDispObj);
      }
    }
    else
    {
      this->pDispObj->OnEventLoad(this->pDispObj);
    }
  }
  if ( v5 && ((unsigned __int8)v5 & 1) == 0 )
  {
    RefCount = v5->RefCount;
    if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
    {
      v5->RefCount = RefCount - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v5);
    }
  }
}
