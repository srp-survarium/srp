unsigned int __thiscall vostok::animation::skeleton::get_bone_index(
        vostok::animation::skeleton *this,
        const vostok::animation::skeleton_bone *bone)
{
  unsigned int result; // [esp+Ch] [ebp-4h]

  result = bone - vostok::animation::skeleton::get_root(this, (int)this);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)0x14);
  return result;
}


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
