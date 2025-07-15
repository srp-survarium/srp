bool __cdecl Scaleform::SIMD::SSE::InstructionSet::SupportsIntegerIntrinsics()
{
  bool result; // al

  if ( (`Scaleform::SIMD::SSE::InstructionSet::SupportsIntegerIntrinsics'::`2'::`local static guard' & 1) != 0 )
    return `Scaleform::SIMD::SSE::InstructionSet::SupportsIntegerIntrinsics'::`2'::HasSSE2;
  `Scaleform::SIMD::SSE::InstructionSet::SupportsIntegerIntrinsics'::`2'::`local static guard' |= 1u;
  _EAX = 1;
  __asm { cpuid }
  result = (_EDX & 0x4000000) != 0;
  `Scaleform::SIMD::SSE::InstructionSet::SupportsIntegerIntrinsics'::`2'::HasSSE2 = result;
  return result;
}
