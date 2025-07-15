void __cdecl Scaleform::GFx::AS2::AvmTextField::SetImageSubstitutions(const Scaleform::GFx::AS2::FnCall *fn)
{
  const Scaleform::GFx::AS2::FnCall *v1; // ebx
  Scaleform::GFx::AS2::Value *Result; // esi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // esi
  Scaleform::GFx::TextField *v4; // edi
  Scaleform::GFx::AS2::Value *v5; // eax
  Scaleform::GFx::AS2::Object *v6; // eax
  Scaleform::GFx::AS2::Object *v7; // ebp
  int v8; // esi
  Scaleform::GFx::AS2::Value *v9; // eax
  Scaleform::GFx::ASString *Name; // eax
  Scaleform::GFx::ASStringNode *v11; // eax
  Scaleform::GFx::AS2::Environment *Env; // [esp-Ch] [ebp-14h]

  v1 = fn;
  Result = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(Result);
  Result->T.Type = 2;
  Result->V.BooleanValue = 0;
  if ( v1->ThisPtr && v1->ThisPtr->GetObjectType(v1->ThisPtr) == Object_TextField )
  {
    ThisPtr = v1->ThisPtr;
    v4 = (unsigned int)(ThisPtr->GetObjectType(ThisPtr) - 2) > 3 ? 0 : (Scaleform::GFx::TextField *)ThisPtr[1].__vftable;
    if ( v1->NArgs >= 1 )
    {
      if ( Scaleform::GFx::AS2::FnCall::Arg(v1, 0)->T.Type == 1 )
      {
        Scaleform::GFx::TextField::ClearIdImageDescAssoc(v4);
        Scaleform::GFx::TextField::ClearImageSubstitutor(v4);
        v4->pDocument.pObject->RTFlags |= 2u;
        Scaleform::GFx::TextField::SetDirtyFlag(v4);
      }
      else
      {
        Env = v1->Env;
        v5 = Scaleform::GFx::AS2::FnCall::Arg(v1, 0);
        v6 = Scaleform::GFx::AS2::Value::ToObject(v5, Env);
        v7 = v6;
        if ( v6 )
        {
          if ( v6->GetObjectType(&v6->Scaleform::GFx::AS2::ObjectInterface) == Object_Array )
          {
            v8 = 0;
            fn = (const Scaleform::GFx::AS2::FnCall *)v7[1].RootIndex;
            if ( (int)fn > 0 )
            {
              do
              {
                Scaleform::GFx::AS2::AvmTextField::ProceedImageSubstitution(
                  (Scaleform::GFx::AS2::AvmTextField *)(&v4->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                      + v4->AvmObjOffset),
                  v1,
                  v8,
                  (Scaleform::GFx::AS2::Value *)(&v7[1].pRCC->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::$C9E2C53B7BF33D1B05D56CCE19B38030::__vftable)[v8]);
                ++v8;
              }
              while ( v8 < (int)fn );
            }
          }
          else
          {
            v9 = Scaleform::GFx::AS2::FnCall::Arg(v1, 0);
            Scaleform::GFx::AS2::AvmTextField::ProceedImageSubstitution(
              (Scaleform::GFx::AS2::AvmTextField *)(&v4->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                  + v4->AvmObjOffset),
              v1,
              0,
              v9);
          }
        }
        else
        {
          Name = Scaleform::GFx::DisplayObject::GetName(v4, (Scaleform::GFx::ASString *)&fn);
          Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptWarning(
            &v4->Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>,
            "%s.setImageSubstitutions() failed: parameter should be either 'null', object or array",
            Name->pNode->pData);
          v11 = (Scaleform::GFx::ASStringNode *)fn;
          --fn->ThisFunctionRef.Function;
          if ( !v11->RefCount )
            Scaleform::GFx::ASStringNode::ReleaseNode(v11);
        }
      }
    }
  }
}
