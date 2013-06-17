#include "libqupdownio.h"


Qupdownio::Qupdownio(QObject *parent, const QString &p_apiKey) : QObject(parent),m_apiKey(p_apiKey),m_baseUrl("https://beta.updown.io/api")
{
	m_parser = new QJson::Parser();
	m_networkManager = new QNetworkAccessManager(this);
	connect(m_networkManager,SIGNAL(finished(QNetworkReply*)),this,SLOT(requestFinished(QNetworkReply*)));
}

Qupdownio::~Qupdownio(){
	delete m_networkManager;
	delete m_parser;
}

QVariantMap Qupdownio::replyToJson(QNetworkReply *p_reply){
	QString json = p_reply->readAll();
	bool ok = false;
	QVariantMap result = m_parser->parse(json.toUtf8(), &ok).toMap();
	if(ok){
		return result;
	}
	else{
		return QVariantMap();
	}
}

void Qupdownio::setProxy(const QNetworkProxy &p_proxy){
	m_networkManager->setProxy(p_proxy);
}

void Qupdownio::setApiKey(const QString &p_apiKey){
	m_apiKey = p_apiKey;
}

const QString& Qupdownio::apiKey(){
	return m_apiKey;
}

void Qupdownio::checks(){
	m_networkManager->get( QNetworkRequest( QUrl( m_baseUrl+"/checks?api-key="+m_apiKey ) ) );
}

void Qupdownio::downtimes(const QString &p_token, const int &p_page){
	m_networkManager->get( QNetworkRequest( QUrl( m_baseUrl+"checks/"+p_token+"/downtimes?api-key="+m_apiKey+"&page="+p_page ) ) );
}

void Qupdownio::addCheck(const QString &p_url, const int &p_period, const bool &p_published){
	QByteArray ba;
	ba.append( "url="+p_url );
	ba.append( "period="+p_period );
	ba.append( "published="+p_published );
	m_networkManager->post( QNetworkRequest( QUrl( m_baseUrl+"checks?api-key="+m_apiKey ) ), ba );
}

void Qupdownio::updateCheck(const QString &p_token, const QString &p_url, const int &p_period, const bool &p_published){
	//
}

void Qupdownio::deleteCheck(const QString &p_token){
	//
}

void Qupdownio::requestFinished(QNetworkReply *p_reply){
	//
}
