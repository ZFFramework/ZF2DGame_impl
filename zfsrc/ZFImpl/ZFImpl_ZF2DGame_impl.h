/**
 * @file ZFImpl_ZF2DGame_impl.h
 * @brief global header for ZF2DGame_impl module
 */

#ifndef _ZFI_ZFImpl_ZF2DGame_impl_h_
#define _ZFI_ZFImpl_ZF2DGame_impl_h_

#include "ZFImpl/ZFImpl_ZF_impl.h"

ZF_NAMESPACE_GLOBAL_BEGIN

/** @brief used to export symbols */
#ifndef ZFLIB_ZF2DGame_impl
    #define ZFLIB_ZF2DGame_impl ZF_ENV_IMPORT
#endif
// export a dummy class to ensure the lib really "contains" something
zfclassNotPOD ZFLIB_ZF2DGame_impl _ZFP_ZFLIB_ZF2DGame_impl {};

ZF_NAMESPACE_GLOBAL_END
#endif // #ifndef _ZFI_ZFImpl_ZF2DGame_impl_h_

