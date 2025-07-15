void __cdecl Scaleform::GFx::AS2::AvmTextField::UpdateImageSubstitution(const Scaleform::GFx::AS2::FnCall *fn)
{
  const Scaleform::GFx::AS2::FnCall *v1; // esi
  Scaleform::GFx::AS2::Value *Result; // edi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // edi
  Scaleform::GFx::TextField *v4; // edi
  Scaleform::GFx::AS2::Environment *Env; // ebp
  Scaleform::GFx::AS2::Value *v6; // eax
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *p_mHash; // ebp
  Scaleform::String *pNode; // ebx
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *v9; // eax
  Scaleform::Render::Text::ImageDesc **v10; // ebp
  bool v11; // cc
  Scaleform::Render::Text::ImageDesc *v12; // ebp
  Scaleform::GFx::AS2::Value *v13; // eax
  Scaleform::GFx::AS2::Value *v14; // eax
  Scaleform::GFx::AS2::Object *v15; // eax
  Scaleform::GFx::AS2::Object *v16; // esi
  Scaleform::GFx::AS2::Object_vtbl *v17; // ebx
  Scaleform::GFx::Resource *v18; // eax
  Scaleform::GFx::Resource *v19; // esi
  int v20; // ebp
  int SetValue; // ebx
  Scaleform::GFx::ResourceReport *(__thiscall *GetResourceReport)(Scaleform::GFx::Resource *); // eax
  Scaleform::GFx::Resource *v23; // esi
  Scaleform::RefCountVImpl *v24; // eax
  Scaleform::MemoryHeap *v25; // eax
  Scaleform::GFx::Resource_vtbl *v26; // edx
  Scaleform::GFx::ResourceReport *(__thiscall *v27)(Scaleform::GFx::Resource *); // eax
  Scaleform::RefCountVImpl *v28; // esi
  Scaleform::Render::Text::ImageDesc *v29; // ebx
  Scaleform::Render::Image *pObject; // ecx
  Scaleform::Render::Text::DocView::ImageSubstitutor *ImageSubstitutor; // eax
  Scaleform::GFx::AS2::Environment *v33; // [esp+0h] [ebp-40h]
  Scaleform::GFx::ASString v34; // [esp+14h] [ebp-2Ch] BYREF
  Scaleform::GFx::Resource *v35; // [esp+18h] [ebp-28h]
  Scaleform::Render::Text::ImageDesc *v36; // [esp+1Ch] [ebp-24h]
  _DWORD v37[8]; // [esp+20h] [ebp-20h] BYREF

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
      Env = v1->Env;
      v6 = Scaleform::GFx::AS2::FnCall::Arg(v1, 0);
      Scaleform::GFx::AS2::Value::ToStringImpl(v6, &v34, Env, -1, 0);
      p_mHash = &v4->pImageDescAssoc->mHash;
      pNode = (Scaleform::String *)v34.pNode;
      if ( p_mHash )
      {
        Scaleform::String::String((Scaleform::String *)&fn, (const __m128i *)v34.pNode->pData);
        v9 = Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::GetAlt<Scaleform::String>(
               p_mHash,
               (const Scaleform::String *)&fn);
        v10 = v9 ? (Scaleform::Render::Text::ImageDesc **)&v9->SizeMask : 0;
        Scaleform::String::~String((Scaleform::String *)&fn);
        if ( v10 )
        {
          v11 = v1->NArgs < 2;
          v12 = *v10;
          v36 = v12;
          if ( !v11 )
          {
            if ( Scaleform::GFx::AS2::FnCall::Arg(v1, 1)->T.Type == 1
              || (v13 = Scaleform::GFx::AS2::FnCall::Arg(v1, 1), Scaleform::GFx::AS2::Value::IsUndefined(v13)) )
            {
              ImageSubstitutor = Scaleform::GFx::TextField::CreateImageSubstitutor(v4);
              if ( ImageSubstitutor )
              {
                Scaleform::Render::Text::DocView::ImageSubstitutor::RemoveImageDesc(ImageSubstitutor, v12);
                v4->pDocument.pObject->RTFlags |= 2u;
                Scaleform::GFx::TextField::RemoveIdImageDescAssoc(v4, (Scaleform::String)pNode->pData);
                Scaleform::GFx::TextField::SetDirtyFlag(v4);
              }
            }
            else
            {
              v33 = v1->Env;
              v14 = Scaleform::GFx::AS2::FnCall::Arg(v1, 1);
              v15 = Scaleform::GFx::AS2::Value::ToObject(v14, v33);
              v16 = v15;
              if ( v15 && v15->GetObjectType(&v15->Scaleform::GFx::AS2::ObjectInterface) == Object_BitmapData )
              {
                v17 = v16[1].Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable;
                v18 = v4->GetResourceMovieDef(v4);
                v19 = v18;
                v35 = v18;
                if ( v18 )
                  Scaleform::RefCountImpl::AddRef(v18);
                v20 = 0;
                if ( (*(int (__thiscall **)(void (__thiscall *)(Scaleform::GFx::AS2::Object *, Scaleform::GFx::AS2::Environment *, const Scaleform::GFx::AS2::Value *)))(*(_DWORD *)v17->SetValue + 12))(v17->SetValue) )
                {
                  SetValue = (int)v17->SetValue;
                  if ( SetValue )
                    (*(void (__thiscall **)(int))(*(_DWORD *)SetValue + 4))(SetValue);
                  v20 = SetValue;
                }
                else
                {
                  GetResourceReport = v19[1].GetResourceReport;
                  v23 = v19 + 1;
                  v24 = (Scaleform::RefCountVImpl *)((int (__thiscall *)(Scaleform::GFx::Resource *, int))GetResourceReport)(
                                                      v23,
                                                      11);
                  LOBYTE(fn) = v24 == 0;
                  if ( v24 )
                    Scaleform::RefCountImpl::Release(v24);
                  if ( (_BYTE)fn )
                  {
                    Scaleform::LogDebugMessage(
                      (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)&loc_20FFD + 3),
                      "ImageCreator is null in UpdateImageSubstitution");
                  }
                  else
                  {
                    v25 = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, v4);
                    v26 = v23->__vftable;
                    v37[1] = v25;
                    v37[2] = 1;
                    v37[3] = 1;
                    memset(&v37[4], 0, 16);
                    v27 = v26->GetResourceReport;
                    v37[0] = 3;
                    v28 = (Scaleform::RefCountVImpl *)((int (__thiscall *)(Scaleform::GFx::Resource *, int))v27)(
                                                        v23,
                                                        11);
                    v20 = ((int (__thiscall *)(Scaleform::RefCountVImpl *, _DWORD *, _DWORD))v28->__vftable[1].AddRef)(
                            v28,
                            v37,
                            v17->SetValue);
                    Scaleform::RefCountImpl::Release(v28);
                  }
                  v19 = v35;
                }
                if ( v20 )
                  (*(void (__thiscall **)(int))(*(_DWORD *)v20 + 4))(v20);
                v29 = v36;
                pObject = v36->pImage.pObject;
                if ( pObject )
                  pObject->Release(pObject);
                v29->pImage.pObject = (Scaleform::Render::Image *)v20;
                Scaleform::GFx::TextField::SetDirtyFlag(v4);
                if ( v20 )
                  (*(void (__thiscall **)(int))(*(_DWORD *)v20 + 8))(v20);
                if ( v19 )
                  Scaleform::GFx::Resource::Release(v19);
                pNode = (Scaleform::String *)v34.pNode;
              }
            }
          }
        }
      }
      if ( pNode[3].HeapTypeBits-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)pNode);
    }
  }
}
