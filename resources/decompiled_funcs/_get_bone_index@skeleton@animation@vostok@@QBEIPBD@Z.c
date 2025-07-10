int __usercall vostok::animation::skeleton::get_bone_index@<eax>(vostok::animation::skeleton *this@<ecx>, int a2@<eax>)
{
  return ((int)&stlp_std::priv::__find_if<vostok::animation::skeleton_bone const *,bone_id_predicate>(
                  (const vostok::animation::skeleton_bone *)(a2 + 272),
                  (const vostok::animation::skeleton_bone *)(a2 + 20 * *(_DWORD *)(a2 + 264) + 272),
                  (bone_id_predicate)this)[-13]
        - a2
        - 12)
       / 20;
}
