void __thiscall Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::dispatchEvent(
        Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *this,
        bool *result,
        Scaleform::GFx::AS3::Instances::fl_events::Event *event)
{
  Scaleform::GFx::AS3::Instances::fl_events::Event *v3; // esi
  Scaleform::GFx::AS3::VM *v5; // esi
  const Scaleform::GFx::AS3::VM::Error *v6; // eax
  Scaleform::GFx::ASStringNode *v7; // eax
  Scaleform::GFx::AS3::Instances::fl_events::Event *VInt; // ebx
  Scaleform::GFx::AS3::Traits *pObject; // eax
  Scaleform::GFx::ASString *ConstString; // eax
  Scaleform::GFx::ASStringNode *v11; // eax
  Scaleform::GFx::AS3::VM *pVM; // ecx
  Scaleform::GFx::AS3::Value::V1U v13; // eax
  Scaleform::GFx::AS3::Value::V1U v14; // ecx
  const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *v15; // eax
  unsigned int RefCount; // edx
  Scaleform::GFx::AS3::Instances::fl_events::Event *v17; // ecx
  Scaleform::GFx::ASStringNode *v18; // eax
  Scaleform::GFx::AS3::VM *v19; // esi
  const Scaleform::GFx::AS3::VM::Error *v20; // eax
  Scaleform::GFx::ASStringNode *v21; // eax
  Scaleform::GFx::AS3::Traits *v22; // eax
  unsigned int v23; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> newEvent; // [esp+Ch] [ebp-60h] BYREF
  Scaleform::GFx::ASStringNode *v25; // [esp+10h] [ebp-5Ch]
  Scaleform::GFx::AS3::Value v26; // [esp+14h] [ebp-58h] BYREF
  Scaleform::GFx::AS3::Value cloneMethod; // [esp+24h] [ebp-48h] BYREF
  Scaleform::GFx::AS3::Value _this; // [esp+34h] [ebp-38h] BYREF
  Scaleform::GFx::AS3::Value v; // [esp+44h] [ebp-28h] BYREF
  Scaleform::GFx::AS3::Multiname cloneMethodName; // [esp+54h] [ebp-18h] BYREF

  v3 = event;
  if ( event )
  {
    VInt = 0;
    newEvent.pObject = 0;
    if ( Scaleform::GFx::AS3::Instances::fl_events::Event::NeedsCloning(event) )
    {
      if ( (v3->pTraits.pObject->Flags & 0x10) != 0 )
      {
        Scaleform::GFx::AS3::Value::Value(&_this, &v3->Scaleform::GFx::AS3::Instances::fl::Object);
        pObject = this->pTraits.pObject;
        v26.Flags = 0;
        v26.Bonus.pWeakProxy = 0;
        cloneMethod.Flags = 0;
        cloneMethod.Bonus.pWeakProxy = 0;
        ConstString = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62>::CreateConstString(
                        pObject->pVM->StringManagerRef,
                        (Scaleform::GFx::ASString *)&event,
                        "clone");
        Scaleform::GFx::AS3::Value::Value(&v, ConstString);
        Scaleform::GFx::AS3::Multiname::Multiname(
          &cloneMethodName,
          this->pTraits.pObject->pVM->PublicNamespace.pObject,
          &v);
        if ( (v.Flags & 0x1F) > 9 )
        {
          if ( (v.Flags & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
        }
        v11 = (Scaleform::GFx::ASStringNode *)event;
        --event->pPrev;
        if ( !v11->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v11);
        if ( v3->GetProperty(v3, (Scaleform::GFx::AS3::CheckResult *)&event, &cloneMethodName, &cloneMethod)->Result )
        {
          Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(
            this->pTraits.pObject->pVM,
            &cloneMethod,
            &_this,
            &v26,
            0,
            0,
            0);
          pVM = this->pTraits.pObject->pVM;
          if ( pVM->HandleException )
          {
            Scaleform::GFx::AS3::Multiname::~Multiname(&cloneMethodName);
            Scaleform::GFx::AS3::Value::~Value(&cloneMethod);
            Scaleform::GFx::AS3::Value::~Value(&v26);
            Scaleform::GFx::AS3::Value::~Value(&_this);
            Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>::~SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>(&newEvent);
            return;
          }
          if ( (v26.Flags & 0x1F) - 12 <= 3
            && Scaleform::GFx::AS3::VM::IsOfType(
                 pVM,
                 &v26,
                 *(const Scaleform::GFx::AS3::ClassTraits::Traits **)(pVM[1].InInitializer + 20)) )
          {
            v13 = v26.value.VS._1;
            v14 = v26.value.VS._1;
            if ( v26.value.VS._1.VInt )
            {
              ++*(_DWORD *)(v26.value.VS._1.VInt + 16);
              *(_DWORD *)(v13.VInt + 16) &= 0x8FBFFFFF;
              VInt = (Scaleform::GFx::AS3::Instances::fl_events::Event *)v14.VInt;
            }
          }
        }
        Scaleform::GFx::AS3::Multiname::~Multiname(&cloneMethodName);
        if ( (cloneMethod.Flags & 0x1F) > 9 )
        {
          if ( (cloneMethod.Flags & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef(&cloneMethod);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal(&cloneMethod);
        }
        if ( (v26.Flags & 0x1F) > 9 )
        {
          if ( (v26.Flags & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v26);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal(&v26);
        }
        if ( (_this.Flags & 0x1F) > 9 )
        {
          if ( (_this.Flags & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef(&_this);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
        }
      }
      else
      {
        v15 = (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)v3->Clone(v3, (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *)&event);
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>::Set(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&newEvent,
          v15);
        if ( event )
        {
          if ( ((unsigned __int8)event & 1) == 0 )
          {
            RefCount = event->RefCount;
            v17 = event;
            if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
            {
              event->RefCount = RefCount - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v17);
            }
          }
        }
        VInt = newEvent.pObject;
      }
    }
    else
    {
      v3->RefCount = (v3->RefCount + 1) & 0x8FBFFFFF;
      VInt = v3;
    }
    if ( VInt )
    {
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&VInt->Target,
        (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)this);
      v22 = this->pTraits.pObject;
      if ( (unsigned int)(v22->TraitsType - 17) > 0xC || (v22->Flags & 0x20) != 0 )
      {
        *((_BYTE *)VInt + 48) |= 0x20u;
        Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DispatchSingleEvent(this, VInt, 0);
      }
      else
      {
        Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DoDispatchEvent(
          this,
          VInt,
          (Scaleform::GFx::DisplayObject *)this[1]._pRCC);
      }
      *result = (*((_BYTE *)VInt + 48) & 4) == 0;
      if ( ((unsigned __int8)VInt & 1) == 0 )
      {
        v23 = VInt->RefCount;
        if ( ((unsigned int)&byte_3FFFFF & v23) != 0 )
        {
          VInt->RefCount = v23 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(VInt);
        }
      }
    }
    else
    {
      event = (Scaleform::GFx::AS3::Instances::fl_events::Event *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                                                    this->pTraits.pObject->pVM->StringManagerRef->pStringManager,
                                                                    "event",
                                                                    5u,
                                                                    0);
      ++event->pPrev;
      Scaleform::GFx::AS3::Value::Value(&v, (const Scaleform::GFx::ASString *)&event);
      v18 = (Scaleform::GFx::ASStringNode *)event;
      --event->pPrev;
      if ( !v18->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v18);
      v19 = this->pTraits.pObject->pVM;
      Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&newEvent, eNullPointerError, v19);
      Scaleform::GFx::AS3::VM::ThrowTypeError(v19, v20);
      v21 = v25;
      --v25->RefCount;
      if ( !v21->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v21);
      if ( (v.Flags & 0x1F) > 9 )
      {
        if ( (v.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
      }
    }
  }
  else
  {
    v5 = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&newEvent, eConvertNullToObjectError, v5);
    Scaleform::GFx::AS3::VM::ThrowTypeError(v5, v6);
    v7 = v25;
    --v25->RefCount;
    if ( !v7->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  }
}
