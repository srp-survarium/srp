btOptimizedBvh *__usercall btOptimizedBvh::btOptimizedBvh@<eax>(btOptimizedBvh *this@<ecx>, btQuantizedBvh *a2@<eax>)
{
  btOptimizedBvh *result; // eax

  result = (btOptimizedBvh *)btQuantizedBvh::btQuantizedBvh(this, a2);
  result->__vftable = (btOptimizedBvh_vtbl *)&btOptimizedBvh::`vftable';
  return result;
}
