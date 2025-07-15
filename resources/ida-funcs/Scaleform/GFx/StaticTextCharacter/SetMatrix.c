void __thiscall Scaleform::GFx::StaticTextCharacter::SetMatrix(
        Scaleform::GFx::StaticTextCharacter *this,
        const Scaleform::Render::Matrix2x4<float> *m)
{
  Scaleform::Render::Matrix2x4<float> *p_MatrixPriv; // eax
  Scaleform::Render::Matrix2x4<float> mt; // [esp+10h] [ebp-20h] BYREF

  this->OrigMatrix = *m;
  mt.M[0][0] = m->M[0][0];
  mt.M[0][1] = m->M[0][1];
  mt.M[0][2] = m->M[0][2];
  mt.M[0][3] = m->M[0][3];
  mt.M[1][0] = m->M[1][0];
  mt.M[1][1] = m->M[1][1];
  mt.M[1][2] = m->M[1][2];
  p_MatrixPriv = &this->pDef.pObject->MatrixPriv;
  mt.M[1][3] = m->M[1][3];
  Scaleform::Render::Matrix2x4<float>::Prepend(&mt, p_MatrixPriv);
  Scaleform::GFx::DisplayObject::SetMatrix(this, &mt);
}
