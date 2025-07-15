void __userpurge Scaleform::GFx::AS2::SharedObject::Flush(
        Scaleform::GFx::AS2::SharedObject *this@<ecx>,
        int a2@<ebp>,
        int a3@<esi>,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::ASStringNode *writer,
        int a6,
        Scaleform::GFx::ASStringNode *a7)
{
  Scaleform::GFx::ASStringNode *v7; // edi
  Scaleform::GFx::AS2::GlobalContext *pContext; // eax
  Scaleform::GFx::ASStringNode *v10; // eax
  Scaleform::GFx::AS2::Object *v11; // ebx
  void (__thiscall *v12)(Scaleform::GFx::ASStringNode *); // eax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *> >,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *> >::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *> >,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *> >::NodeHashF> > v13; // [esp+20h] [ebp-1Ch] BYREF
  int (__thiscall **v14)(void *, char); // [esp+24h] [ebp-18h]
  int v15; // [esp+28h] [ebp-14h]
  Scaleform::GFx::AS2::Value v16; // [esp+2Ch] [ebp-10h] BYREF

  v7 = writer;
  if ( writer )
  {
    pContext = penv->StringContext.pContext;
    v16.T.Type = 0;
    writer = Scaleform::GFx::ASStringManager::CreateConstStringNode(
               (Scaleform::GFx::ASStringManager *)pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
               "data",
               4u,
               0);
    ++writer->RefCount;
    ((void (__thiscall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASStringNode **, Scaleform::GFx::AS2::Value *, int, int))this->GetMemberRaw)(
      &this->Scaleform::GFx::AS2::ObjectInterface,
      &penv->StringContext,
      &writer,
      &v16,
      a3,
      a2);
    v10 = a7;
    --a7->RefCount;
    if ( !v10->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v10);
    v11 = Scaleform::GFx::AS2::Value::ToObject((Scaleform::GFx::AS2::Value *)((char *)&v16.NV.NumberValue + 4), penv);
    v12 = (void (__thiscall *)(Scaleform::GFx::ASStringNode *))*((_DWORD *)v7->pData + 1);
    v14 = &`Scaleform::GFx::AS2::SharedObject::Flush'::`4'::DataWriter::`vftable';
    v15 = 0;
    *(_QWORD *)&v16.T.Type = __PAIR64__((unsigned int)v7, (unsigned int)penv);
    v12(v7);
    ((void (__thiscall *)(Scaleform::GFx::AS2::ObjectInterface *))v11->VisitMembers)(&v11->Scaleform::GFx::AS2::ObjectInterface);
    (*((void (__thiscall **)(Scaleform::GFx::ASStringNode *))v7->pData + 7))(v7);
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>,Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Object *,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>,Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>,Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Object *,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>,Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>::NodeHashF>>(&v13);
    if ( v16.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v16);
  }
}
