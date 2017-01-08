#ifndef __IRENDERCONTEXT_H__
#define __IRENDERCONTEXT_H__

struct SVertex;
struct SMesh;

enum EContextType
{
	ECT_OPENGL_3_0,
	ECT_DIRECTX_9_0
};

class IRenderContext
{
public:
	virtual ~IRenderContext() {};
	virtual bool IsValid() = 0;
	virtual void UploadMesh(SMesh* mesh) = 0;
};

#endif // !__IRENDERCONTEXT_H__
