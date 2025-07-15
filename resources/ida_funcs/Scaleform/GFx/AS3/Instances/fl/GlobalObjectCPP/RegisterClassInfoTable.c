void __thiscall Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::RegisterClassInfoTable(
        Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *this,
        const Scaleform::GFx::AS3::ClassInfo **table)
{
  const Scaleform::GFx::AS3::ClassInfo **v2; // ebx
  const Scaleform::GFx::AS3::ClassInfo *v3; // edx
  int v4; // edi
  Scaleform::GFx::AS3::Instances::fl::ConstStringHash<Scaleform::GFx::AS3::ClassInfo const *> *p_CIRegistrationHash; // esi
  const Scaleform::GFx::AS3::ClassInfo *const *v6; // eax
  const Scaleform::GFx::AS3::ClassInfo **Name; // ecx
  unsigned int v8; // eax
  Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::ConstStringKey,Scaleform::GFx::AS3::ClassInfo const *,Scaleform::GFx::AS3::Instances::fl::ConstStringHashFn>::NodeRef key; // [esp+8h] [ebp-8h] BYREF

  v2 = table;
  v3 = *table;
  v4 = 0;
  if ( *table )
  {
    key.pFirst = (const Scaleform::GFx::AS3::Instances::fl::ConstStringKey *)&table;
    p_CIRegistrationHash = &this->CIRegistrationHash;
    v6 = table;
    do
    {
      Name = (const Scaleform::GFx::AS3::ClassInfo **)v3->Type->Name;
      key.pSecond = v6;
      table = Name;
      v8 = Scaleform::String::BernsteinHashFunction((char *)Name, strlen((const char *)Name), 0x1505u);
      Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::ConstStringKey,Scaleform::GFx::AS3::ClassInfo const *,Scaleform::GFx::AS3::Instances::fl::ConstStringHashFn>,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::ConstStringKey,Scaleform::GFx::AS3::ClassInfo const *,Scaleform::GFx::AS3::Instances::fl::ConstStringHashFn>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::ConstStringKey,Scaleform::GFx::AS3::ClassInfo const *,Scaleform::GFx::AS3::Instances::fl::ConstStringHashFn>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::ConstStringKey,328>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::ConstStringKey,Scaleform::GFx::AS3::ClassInfo const *,Scaleform::GFx::AS3::Instances::fl::ConstStringHashFn>,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::ConstStringKey,Scaleform::GFx::AS3::ClassInfo const *,Scaleform::GFx::AS3::Instances::fl::ConstStringHashFn>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::ConstStringKey,Scaleform::GFx::AS3::ClassInfo const *,Scaleform::GFx::AS3::Instances::fl::ConstStringHashFn>::NodeRef>(
        &p_CIRegistrationHash->mHash,
        p_CIRegistrationHash,
        &key,
        v8);
      v3 = v2[++v4];
      v6 = &v2[v4];
    }
    while ( v3 );
  }
}
