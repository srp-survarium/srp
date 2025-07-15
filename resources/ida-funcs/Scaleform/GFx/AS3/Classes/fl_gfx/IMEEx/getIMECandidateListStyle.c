void __thiscall Scaleform::GFx::AS3::Classes::fl_gfx::IMEEx::getIMECandidateListStyle(
        Scaleform::GFx::AS3::Classes::fl_gfx::IMEEx *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result)
{
  Scaleform::GFx::AS3::Traits *pObject; // ecx
  Scaleform::GFx::AS3::ASVM *pVM; // edi
  Scaleform::GFx::MovieImpl *pMovieImpl; // ecx
  Scaleform::GFx::AS3::Traits *v6; // ecx
  Scaleform::GFx::AS3::Class *Class; // eax
  char Flags; // al
  Scaleform::StringDataPtr gname; // [esp+8h] [ebp-34h] BYREF
  Scaleform::GFx::IMECandidateListStyle st; // [esp+10h] [ebp-2Ch] BYREF

  pObject = this->pTraits.pObject;
  st.Flags = 0;
  pVM = (Scaleform::GFx::AS3::ASVM *)pObject->pVM;
  pMovieImpl = pVM->pMovieRoot->pMovieImpl;
  if ( pMovieImpl )
  {
    Scaleform::GFx::MovieImpl::GetIMECandidateListStyle(pMovieImpl, &st);
    v6 = this->pTraits.pObject;
    gname.pStr = "scaleform.gfx.IMECandidateListStyle";
    gname.Size = 35;
    Class = Scaleform::GFx::AS3::VM::GetClass(v6->pVM, &gname, v6->pVM->CurrentDomain);
    if ( Scaleform::GFx::AS3::ASVM::_constructInstance(pVM, result, Class, 0, 0) )
    {
      Flags = st.Flags;
      if ( (st.Flags & 1) != 0 )
      {
        result->pObject[1].__vftable = (Scaleform::GFx::AS3::Object_vtbl *)(st.TextColor & 0xFFFFFF);
        Flags = st.Flags;
      }
      if ( (Flags & 2) != 0 )
      {
        result->pObject[1].pPrev = (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)(st.BackgroundColor & 0xFFFFFF);
        Flags = st.Flags;
      }
      if ( (Flags & 4) != 0 )
      {
        result->pObject[1].pTraits.pObject = (Scaleform::GFx::AS3::Traits *)(st.IndexBackgroundColor & 0xFFFFFF);
        Flags = st.Flags;
      }
      if ( (Flags & 8) != 0 )
      {
        result->pObject[1].pRCCRaw = st.SelectedTextColor & 0xFFFFFF;
        Flags = st.Flags;
      }
      if ( (Flags & 0x10) != 0 )
      {
        result->pObject[1].RefCount = st.SelectedBackgroundColor & 0xFFFFFF;
        Flags = st.Flags;
      }
      if ( (Flags & 0x20) != 0 )
      {
        result->pObject[1].DynAttrs.mHash.pTable = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> >::TableType *)(st.SelectedIndexBackgroundColor & 0xFFFFFF);
        Flags = st.Flags;
      }
      if ( (Flags & 0x40) != 0 )
      {
        result->pObject[1].pNext = (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)st.FontSize;
        Flags = st.Flags;
      }
      if ( Flags < 0 )
        result->pObject[1].pUserDataHolder = (Scaleform::GFx::AS3::Object::UserDataHolder *)st.ReadingWindowTextColor;
      if ( (st.Flags & 0x100) != 0 )
        result->pObject[2].__vftable = (Scaleform::GFx::AS3::Object_vtbl *)st.ReadingWindowBackgroundColor;
      if ( (st.Flags & 0x200) != 0 )
        result->pObject[2].pRCCRaw = st.ReadingWindowFontSize;
    }
  }
}
