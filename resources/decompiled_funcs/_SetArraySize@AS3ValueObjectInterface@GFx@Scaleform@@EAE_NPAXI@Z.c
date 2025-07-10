char __thiscall Scaleform::GFx::AS3ValueObjectInterface::SetArraySize(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        char *pdata,
        unsigned int sz)
{
  Scaleform::GFx::AS3::Impl::SparseArray::Resize((Scaleform::GFx::AS3::Impl::SparseArray *)(pdata + 32), sz);
  return 1;
}
