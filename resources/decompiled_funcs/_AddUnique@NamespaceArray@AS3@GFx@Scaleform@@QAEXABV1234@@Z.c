void __thiscall Scaleform::GFx::AS3::NamespaceArray::AddUnique(
        Scaleform::GFx::AS3::NamespaceArray *this,
        const Scaleform::GFx::AS3::NamespaceArray *other)
{
  unsigned int Size; // edi
  unsigned int i; // esi

  Size = other->Namespaces.Data.Size;
  for ( i = 0; i < Size; ++i )
    Scaleform::GFx::AS3::NamespaceArray::Add(this, other->Namespaces.Data.Data[i].pObject, 1);
}
