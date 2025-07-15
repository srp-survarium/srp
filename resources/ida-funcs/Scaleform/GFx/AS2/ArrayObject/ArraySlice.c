void __cdecl Scaleform::GFx::AS2::ArrayObject::ArraySlice(const Scaleform::GFx::AS2::FnCall *fn)
{
  const Scaleform::GFx::AS2::FnCall *v1; // edi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *p_pProto; // ebx
  int pObject; // ecx
  int v5; // esi
  Scaleform::GFx::AS2::Value *v6; // eax
  int v7; // eax
  Scaleform::GFx::AS2::Value *v8; // eax
  int v9; // eax
  int v10; // ecx
  Scaleform::GFx::AS2::ArrayObject *v11; // ebx
  int i; // ebp
  Scaleform::GFx::AS2::Object *v13; // ecx
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *p_Elements; // edi
  unsigned int v15; // esi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *v16; // eax
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Environment *Env; // [esp-Ch] [ebp-1Ch]
  Scaleform::GFx::AS2::Environment *v19; // [esp-Ch] [ebp-1Ch]
  int v20; // [esp+8h] [ebp-8h]
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *v21; // [esp+Ch] [ebp-4h]

  v1 = fn;
  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_Array )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
    {
      p_pProto = &ThisPtr[-2].pProto;
      v21 = &ThisPtr[-2].pProto;
    }
    else
    {
      v21 = 0;
      p_pProto = 0;
    }
    pObject = (int)p_pProto[15].pObject;
    LOBYTE(p_pProto[19].pObject) = 0;
    v5 = 0;
    v20 = pObject;
    if ( fn->NArgs >= 1 )
    {
      Env = fn->Env;
      v6 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
      v7 = Scaleform::GFx::AS2::Value::ToInt32(v6, Env);
      v5 = v7;
      if ( v7 < 0 )
      {
        v5 = (int)p_pProto[15].pObject + v7;
        if ( v5 < 0 )
          v5 = 0;
      }
      if ( v5 > (int)p_pProto[15].pObject )
        v5 = (int)p_pProto[15].pObject;
    }
    if ( fn->NArgs >= 2 )
    {
      v19 = fn->Env;
      v8 = Scaleform::GFx::AS2::FnCall::Arg(fn, 1);
      v9 = Scaleform::GFx::AS2::Value::ToInt32(v8, v19);
      v10 = v9;
      v20 = v9;
      if ( v9 < 0 )
      {
        v10 = (int)p_pProto[15].pObject + v9;
        v20 = v10;
        if ( v10 < 0 )
        {
          v20 = 0;
          v10 = 0;
        }
      }
      if ( v10 > (int)p_pProto[15].pObject )
        v20 = (int)p_pProto[15].pObject;
    }
    v11 = (Scaleform::GFx::AS2::ArrayObject *)Scaleform::GFx::AS2::Environment::OperatorNew(
                                                fn->Env,
                                                fn->Env->StringContext.pContext->pGlobal.pObject,
                                                (const Scaleform::GFx::ASString *)&fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[8].pASSupport,
                                                0,
                                                -1);
    if ( v11 )
    {
      for ( i = v5; i < v20; ++i )
      {
        v13 = v21[14].pObject;
        if ( *((_DWORD *)&v13->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable
             + i) )
        {
          Scaleform::GFx::AS2::ArrayObject::PushBack(
            v11,
            *((const Scaleform::GFx::AS2::Value **)&v13->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable
            + i));
        }
        else
        {
          p_Elements = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&v11->Elements;
          v15 = v11->Elements.Data.Size + 1;
          if ( v15 >= v11->Elements.Data.Size )
          {
            if ( v15 >= v11->Elements.Data.Policy.Capacity )
              Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                p_Elements,
                p_Elements,
                v15 + (v15 >> 2));
          }
          else if ( v15 < v11->Elements.Data.Policy.Capacity >> 1 )
          {
            Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              p_Elements,
              p_Elements,
              v11->Elements.Data.Size + 1);
          }
          v16 = &p_Elements->Data[v15 - 1];
          v11->Elements.Data.Size = v15;
          v1 = fn;
          if ( v16 )
            v16->pObject = 0;
        }
      }
    }
    Scaleform::GFx::AS2::Value::SetAsObject(v1->Result, v11);
    if ( v11 )
    {
      RefCount = v11->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        v11->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v11);
      }
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "Array");
  }
}
