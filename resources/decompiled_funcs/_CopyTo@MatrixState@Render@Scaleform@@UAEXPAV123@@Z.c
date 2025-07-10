void __thiscall Scaleform::Render::MatrixState::CopyTo(
        Scaleform::Render::MatrixState *this,
        Scaleform::Render::MatrixState *state)
{
  Scaleform::Render::MatrixState::Copy(state, this);
}
