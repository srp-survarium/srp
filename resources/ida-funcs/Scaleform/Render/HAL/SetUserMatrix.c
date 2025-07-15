void __thiscall Scaleform::Render::HAL::SetUserMatrix(
        Scaleform::Render::HAL *this,
        const Scaleform::Render::Matrix2x4<float> *m)
{
  this->Matrices.pObject->SetUserMatrix(this->Matrices.pObject, m);
}
