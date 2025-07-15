void __thiscall Scaleform::GFx::AS3::TR::State::exec_jump(Scaleform::GFx::AS3::TR::State *this, unsigned int *bcp)
{
  Scaleform::GFx::AS3::Tracer *pTracer; // edi
  int v4; // eax

  pTracer = this->pTracer;
  v4 = Scaleform::GFx::AS3::Abc::ReadS24<unsigned char>(this->pTracer->pCode, bcp);
  Scaleform::GFx::AS3::Tracer::StoreOffset(pTracer, *bcp, this, v4, -1);
  Scaleform::GFx::AS3::Tracer::AddBlock(pTracer, this, *bcp, tDead, (Scaleform::GFx::AS3::TR::State *)1);
}
