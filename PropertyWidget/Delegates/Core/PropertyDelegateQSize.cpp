/*
   Copyright (c) 2012-1015 Alex Zhondin <qtinuum.team@gmail.com>

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#include "PropertyDelegateQSize.h"
#include "../../../Core/Core/PropertyQSize.h"
#include "../PropertyDelegateFactory.h"

#include <QLineEdit>
#include <QLocale>

static bool regQSizeDelegate = QtnPropertyDelegateFactory::staticInstance()
                                .registerDelegateDefault(&QtnPropertyQSizeBase::staticMetaObject
                                , &qtnCreateDelegate<QtnPropertyDelegateQSize, QtnPropertyQSizeBase>
                                , "WH");

QtnPropertyDelegateQSize::QtnPropertyDelegateQSize(QtnPropertyQSizeBase& owner)
    : QtnPropertyDelegateTypedEx<QtnPropertyQSizeBase>(owner)
{
    addSubProperty(qtnCreateWidthProperty(0, &owner));
    addSubProperty(qtnCreateHeightProperty(0, &owner));
}

QWidget* QtnPropertyDelegateQSize::createValueEditorImpl(QWidget* parent, const QRect& rect, QtnInplaceInfo* inplaceInfo)
{
    return createValueEditorLineEdit(parent, rect, true, inplaceInfo);
}

bool QtnPropertyDelegateQSize::propertyValueToStr(QString& strValue) const
{
	auto value = owner().value();

	QLocale locale;
	strValue = QtnPropertyQSize::getToStringFormat().arg(locale.toString(value.width()),
														 locale.toString(value.height()));

	return true;
}
