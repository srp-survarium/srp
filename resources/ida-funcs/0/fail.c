Scaleform::Render::Text::CompositionStringBase *(__thiscall *__thiscall Scaleform::GFx::TextField::GetBeginIndex(
        Scaleform::GFx::TextField *this))(Scaleform::Render::Text::EditorKitBase *this)
{
  Scaleform::Render::Text::EditorKitBase *pObject; // eax
  Scaleform::Render::Text::EditorKitBase_vtbl *v2; // eax
  unsigned int v3; // ecx
  Scaleform::Render::Text::CompositionStringBase *(__thiscall *result)(Scaleform::Render::Text::EditorKitBase *); // eax

  pObject = this->pDocument.pObject->pEditorKit.pObject;
  if ( !pObject )
    return 0;
  v2 = pObject[1].__vftable;
  v3 = (unsigned int)v2[1].~Scaleform::Render::Text::EditorKitBase;
  result = v2->GetCompositionString;
  if ( (unsigned int)result >= v3 )
    return (Scaleform::Render::Text::CompositionStringBase *(__thiscall *)(Scaleform::Render::Text::EditorKitBase *))v3;
  return result;
}


Scaleform::Render::Text::CompositionStringBase *(__thiscall *__thiscall Scaleform::GFx::TextField::GetEndIndex(
        Scaleform::GFx::TextField *this))(Scaleform::Render::Text::EditorKitBase *this)
{
  Scaleform::Render::Text::EditorKitBase *pObject; // eax
  Scaleform::Render::Text::EditorKitBase_vtbl *v2; // eax
  unsigned int v3; // ecx
  Scaleform::Render::Text::CompositionStringBase *(__thiscall *result)(Scaleform::Render::Text::EditorKitBase *); // eax

  pObject = this->pDocument.pObject->pEditorKit.pObject;
  if ( !pObject )
    return 0;
  v2 = pObject[1].__vftable;
  v3 = (unsigned int)v2[1].~Scaleform::Render::Text::EditorKitBase;
  result = v2->GetCompositionString;
  if ( v3 >= (unsigned int)result )
    return (Scaleform::Render::Text::CompositionStringBase *(__thiscall *)(Scaleform::Render::Text::EditorKitBase *))v3;
  return result;
}


const unsigned __int8 (*__thiscall vostok::sound::sound_world::get_x3daudio(vostok::sound::sound_world *this))[20]
{
  return (const unsigned __int8 (*)[20])this->m_x3d_instance;
}


survarium::inventory_item *(__thiscall *__usercall vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator survarium::inventory_item * (__thiscall vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::*)(void)const@<eax>(
        vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *this@<ecx>,
        _DWORD *a2@<eax>))(vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *this)
{
  return *a2 != 0
       ? (survarium::inventory_item *(__thiscall *)(vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *))vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
       : 0;
}
