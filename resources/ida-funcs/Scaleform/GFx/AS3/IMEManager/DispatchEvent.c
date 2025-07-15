void __thiscall Scaleform::GFx::AS3::IMEManager::DispatchEvent(
        Scaleform::GFx::AS3::IMEManager *this,
        char *message,
        char *messageType,
        char *type)
{
  Scaleform::GFx::ASMovieRootBase *pObject; // ebp
  Scaleform::GFx::DisplayObject *pLangContext2; // edi
  Scaleform::GFx::DisplayObject *pStatusContext2; // esi
  int v7; // eax
  int v8; // ebx
  Scaleform::GFx::ASMovieRootBase_vtbl *v9; // esi
  Scaleform::GFx::AS3::Class *Class; // eax
  Scaleform::GFx::ASStringNode *v11; // eax
  Scaleform::StringDataPtr avmDispObj; // [esp+0h] [ebp-48h] BYREF
  Scaleform::GFx::AS3::Value as3val; // [esp+8h] [ebp-40h] BYREF
  Scaleform::GFx::AS3::Value params[3]; // [esp+18h] [ebp-30h] BYREF

  pObject = this->pMovie->pASMovieRoot.pObject;
  pLangContext2 = this->pLangContext2;
  avmDispObj.pStr = 0;
  as3val.Flags = 0;
  as3val.Bonus.pWeakProxy = 0;
  if ( pLangContext2 && !strcmp(type, "LangBar") )
  {
    avmDispObj.pStr = (const char *)(&pLangContext2->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                   + pLangContext2->AvmObjOffset);
  }
  else
  {
    pStatusContext2 = this->pStatusContext2;
    if ( pStatusContext2 && !strcmp(type, "StatusWindow") )
      avmDispObj.pStr = (const char *)(&pStatusContext2->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                     + pStatusContext2->AvmObjOffset);
  }
  if ( pObject && avmDispObj.pStr )
  {
    v7 = *((_DWORD *)avmDispObj.pStr + 2);
    if ( !v7 )
      v7 = *((_DWORD *)avmDispObj.pStr + 1);
    v8 = v7;
    if ( (v7 & 1) != 0 )
      v8 = v7 - 1;
    messageType = (char *)Scaleform::GFx::ASStringManager::CreateStringNode(
                            (Scaleform::GFx::ASStringManager *)pObject[21].pASSupport.pObject,
                            messageType);
    ++*((_DWORD *)messageType + 3);
    if ( Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::HasEventHandler(
           (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)v8,
           (const Scaleform::GFx::ASString *)&messageType,
           0) )
    {
      type = 0;
      Scaleform::GFx::AS3::Value::Value(params, (const Scaleform::GFx::ASString *)&messageType);
      params[1].Flags = 1;
      params[2].Flags = 1;
      v9 = pObject[2].__vftable;
      params[1].Bonus.pWeakProxy = 0;
      params[1].value.VS._1.VBool = 1;
      params[2].Bonus.pWeakProxy = 0;
      params[2].value.VS._1.VBool = 1;
      Scaleform::StringDataPtr::StringDataPtr(&avmDispObj, "scaleform.gfx.IMEEventEx");
      Class = Scaleform::GFx::AS3::VM::GetClass(
                (Scaleform::GFx::AS3::VM *)v9,
                (Scaleform::GFx::ASStringNode *)&avmDispObj,
                (Scaleform::GFx::ASStringNode *)v9[1].ChangeMouseCursorType);
      Scaleform::GFx::AS3::ASVM::_constructInstance(
        (Scaleform::GFx::AS3::ASVM *)v9,
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&type,
        Class,
        3u,
        params);
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)type + 10,
        (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)v8);
      Scaleform::GFx::ASString::operator=((Scaleform::GFx::ASString *)type + 13, message);
      Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Dispatch(
        (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)v8,
        (Scaleform::GFx::AS3::Instances::fl_events::Event *)type,
        *(Scaleform::GFx::DisplayObject **)(v8 + 48));
      `vector destructor iterator'(
        (char *)params,
        0x10u,
        3,
        (void (__thiscall *)(void *))Scaleform::GFx::AS3::Value::~Value);
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>::~SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>((Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *)&type);
    }
    v11 = (Scaleform::GFx::ASStringNode *)messageType;
    --*((_DWORD *)messageType + 3);
    if ( !v11->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  }
  if ( (as3val.Flags & 0x1F) > 9 )
  {
    if ( (as3val.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&as3val);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&as3val);
  }
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(0, 0);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, 0);
}
