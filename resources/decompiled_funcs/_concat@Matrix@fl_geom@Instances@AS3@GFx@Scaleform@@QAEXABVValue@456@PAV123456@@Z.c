void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Matrix::concat(
        Scaleform::GFx::AS3::Instances::fl_geom::Matrix *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_geom::Matrix *m)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v5; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::VM::Error v7; // [esp+8h] [ebp-88h] BYREF
  Scaleform::Render::Matrix2x4<double> m2d; // [esp+10h] [ebp-80h] BYREF
  Scaleform::Render::Matrix2x4<double> v9; // [esp+50h] [ebp-40h] BYREF

  if ( m )
  {
    m2d.M[0][2] = 0.0;
    m2d.M[1][2] = 0.0;
    m2d.M[0][0] = this->a;
    m2d.M[1][0] = this->b;
    m2d.M[0][1] = this->c;
    m2d.M[1][1] = this->d;
    m2d.M[0][3] = this->tx;
    m2d.M[1][3] = this->ty;
    v9.M[0][2] = 0.0;
    v9.M[1][2] = 0.0;
    v9.M[0][0] = m->a;
    v9.M[1][0] = m->b;
    v9.M[0][1] = m->c;
    v9.M[1][1] = m->d;
    v9.M[0][3] = m->tx;
    v9.M[1][3] = m->ty;
    Scaleform::Render::Matrix2x4<double>::Append_NonOpt(&m2d, &v9);
    this->a = m2d.M[0][0];
    this->b = m2d.M[1][0];
    this->c = m2d.M[0][1];
    this->d = m2d.M[1][1];
    this->tx = m2d.M[0][3];
    this->ty = m2d.M[1][3];
  }
  else
  {
    pVM = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v7, eConvertNullToObjectError, pVM);
    Scaleform::GFx::AS3::VM::ThrowTypeError(pVM, v5);
    pNode = v7.Message.pNode;
    --v7.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}
