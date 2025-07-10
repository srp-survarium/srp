void __thiscall Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::SetUnsafe(
        Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> > *this,
        unsigned int ind,
        const Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::AS3::Value::V1U v3; // esi
  Scaleform::Ptr<Scaleform::GFx::ASStringNode> *v4; // edi
  Scaleform::GFx::ASStringNode *pObject; // ecx

  v3 = v->value.VS._1;
  v4 = &this->ValueA.Data.Data[ind];
  if ( v3.VInt )
    ++*(_DWORD *)(v3.VInt + 12);
  pObject = v4->pObject;
  if ( v4->pObject )
  {
    if ( pObject->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pObject);
  }
  v4->pObject = (Scaleform::GFx::ASStringNode *)v3;
}
