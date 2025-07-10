void __thiscall Scaleform::Render::FilterPrimitive::Insert(
        Scaleform::Render::FilterPrimitive *this,
        unsigned int index,
        const Scaleform::Render::MatrixPoolImpl::HMatrix *m)
{
  Scaleform::Render::MatrixPoolImpl::HMatrix::operator=(&this->FilterArea, m);
}
