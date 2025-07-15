void __thiscall Scaleform::GFx::MovieImpl::WideStringStorage::WideStringStorage(
        Scaleform::GFx::MovieImpl::WideStringStorage *this,
        Scaleform::GFx::ASStringNode *pnode)
{
  this->__vftable = (Scaleform::GFx::MovieImpl::WideStringStorage_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->pNode = pnode;
  this->RefCount = 1;
  this->__vftable = (Scaleform::GFx::MovieImpl::WideStringStorage_vtbl *)&Scaleform::GFx::MovieImpl::WideStringStorage::`vftable';
  ++pnode->RefCount;
  Scaleform::UTF8Util::DecodeString((wchar_t *)this->pData, (char *)this->pNode->pData, this->pNode->Size);
}
